import javax.swing.*;
import java.awt.*;
import java.io.File;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.UnsupportedAudioFileException;
import java.io.IOException;

public class QuickSortVisualizer extends JPanel {

    private int[] array;
    private int delay;
    private final int barWidth;
    private final int panelHeight;
    private int cursorPositionI = -1;  // Pointer for `i`
    private int cursorPositionJ = -1;  // Pointer for `j`
    private int animationIndex = -1;
    private long sortingTime = 0;

    // Preloaded audio clips
    private Clip sortClip;
    private Clip completionClip;

    public QuickSortVisualizer(int[] array, int delay) {
        this.array = array;
        this.delay = delay;
        this.barWidth = 5;  // Slightly wider bars for better visibility
        this.panelHeight = 600;  // Increased panel height for better proportion
        setPreferredSize(new Dimension(array.length * barWidth, panelHeight));
        loadSounds();  // Preload audio clips
    }

    // Load and prepare audio clips
    private void loadSounds() {
        try {
            sortClip = AudioSystem.getClip();
            AudioInputStream sortStream = AudioSystem.getAudioInputStream(new File("sort2.wav"));
            sortClip.open(sortStream);

            completionClip = AudioSystem.getClip();
            AudioInputStream completionStream = AudioSystem.getAudioInputStream(new File("completion.wav"));
            completionClip.open(completionStream);
        } catch (UnsupportedAudioFileException | IOException | javax.sound.sampled.LineUnavailableException e) {
            e.printStackTrace();
        }
    }

    // Reuse preloaded audio clips
    private void playSound(Clip clip) {
        if (clip != null) {
            clip.setFramePosition(0); // Reset the clip to the beginning
            clip.start();
        }
    }

    public void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    private int partition(int low, int high) {
        int pivot = array[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            cursorPositionJ = j;  // Set `j` pointer
            if (array[j] < pivot) {
                i++;
                cursorPositionI = i;  // Set `i` pointer
                swap(i, j);
                repaint();
                playSound(sortClip);
                sleep();
            }
        }
        swap(i + 1, high);
        cursorPositionI = i + 1;  // Update `i` pointer
        repaint();
        playSound(sortClip);
        sleep();
        return i + 1;
    }

    private void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    private void sleep() {
        try {
            Thread.sleep(delay);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void animateCompletion() {
        new Thread(() -> {
            for (int i = 0; i < array.length; i++) {
                animationIndex = i;
                repaint();
                sleep();
            }
        }).start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        int height = getHeight();

        // Background color with gradient
        Graphics2D g2d = (Graphics2D) g;
        g2d.setPaint(new GradientPaint(0, 0, new Color(30, 30, 30), getWidth(), getHeight(), new Color(60, 60, 60)));
        g2d.fillRect(0, 0, getWidth(), getHeight());

        // Modern bar colors with shadow effect
        for (int i = 0; i < array.length; i++) {
            int barHeight = array[i] * height / array.length;
            g2d.setColor(i <= animationIndex ? new Color(0xFFBB86FC) : new Color(0xFF03DAC5));  // Modern pastel colors
            g2d.fillRect(i * barWidth, height - barHeight, barWidth, barHeight);

            // Adding shadow effect to the bars
            g2d.setColor(new Color(0, 0, 0, 50));  // Semi-transparent black
            g2d.fillRect(i * barWidth + 2, height - barHeight + 2, barWidth, 2);
        }

        // Draw the `i` pointer in red with thicker stroke
        if (cursorPositionI >= 0 && cursorPositionI < array.length && animationIndex == -1) {
            g2d.setColor(new Color(255, 69, 58));  // Vibrant red
            g2d.setStroke(new BasicStroke(3));  // Thicker line for emphasis
            g2d.drawLine(cursorPositionI * barWidth, 0, cursorPositionI * barWidth, height);
        }

        // Draw the `j` pointer in blue with thicker stroke
        if (cursorPositionJ >= 0 && cursorPositionJ < array.length && animationIndex == -1) {
            g2d.setColor(new Color(0, 122, 255));  // Vibrant blue
            g2d.setStroke(new BasicStroke(3));  // Thicker line for emphasis
            g2d.drawLine(cursorPositionJ * barWidth, 0, cursorPositionJ * barWidth, height);
        }

        if (animationIndex >= array.length - 1) {
            g2d.setColor(new Color(255, 255, 255));  // White text
            g2d.setFont(new Font("Segoe UI", Font.PLAIN, 14));  // Modern font

            // Display information with some padding for better readability
            g2d.drawString("Time Taken: " + sortingTime + " ms", 15, 30);
            g2d.drawString("Number of Elements: " + array.length, 15, 50);
            g2d.drawString("Time Complexity: O(n log n)", 15, 70);
            g2d.drawString("Space Complexity: O(log n)", 15, 90);
            g2d.drawString("Algorithm: Quick_Sort", 15, 110);
        }
    }

    public static void main(String[] args) {
        int[] array = new int[200];

        for (int i = 0; i < array.length; i++) {
            array[i] = (int) (Math.random() * array.length);
        }

        QuickSortVisualizer visualizer = new QuickSortVisualizer(array, 10);

        JFrame frame = new JFrame("QuickSort Visualization");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Applying modern look to the frame
        frame.getContentPane().setBackground(new Color(18, 18, 18));  // Dark background
        frame.add(visualizer);
        frame.pack();
        frame.setLocationRelativeTo(null);  // Center the window
        frame.setVisible(true);

        new Thread(() -> {
            long startTime = System.currentTimeMillis();
            visualizer.quickSort(0, array.length - 1);
            long endTime = System.currentTimeMillis();
            visualizer.sortingTime = endTime - startTime;
            System.out.println("Sorting Completed");
            visualizer.playSound(visualizer.completionClip);
            visualizer.animateCompletion();
        }).start();
    }
}
