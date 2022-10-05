import java.util.Scanner;

public class Menu {
    int numberOfElements, key;
    int elements[];
    int firstDecision, secondDecision;
    Scanner input = new Scanner(System.in);

    public void header() {
        System.out.println("\n\t\t*****************************************************************************");
        System.out.println("\n\t\t\t\t\tSEARCHING AND SORTING ALGORITHMS");
        System.out.println("\n\t\t*****************************************************************************");
        System.out.println("\n");
    }

    public void welcomeMessage() {
        System.out.println("The Algorithms available in this Program are:");
        System.out.println("Searching Algorithms");
        System.out.println("Sorting Algorithms");
        System.out.println();

        System.out.println("Do you want to proceed with Sorting or Searching Algorithm?");
        System.out.print("Enter 0 for Sorting or 1 for Searching Algorithm.......");
        firstDecision = input.nextInt();
        // System.out.println();

        // while (firstDecision < 0 || firstDecision > 2) {
        // System.out.print("Enter 0 for Sorting or 1 for Searching Algorithm.......");
        // firstDecision = input.nextInt();
        if (firstDecision == 0) {
            System.out.println("Searching Algorithms");
            System.out.println("1 Linear Search");
            System.out.println("2 Binary Search");
            System.out.println();
            System.out.println();
        }

        else if (firstDecision == 1) {
            System.out.println("Sorting Algorithms");
            System.out.println("Sorting Algorithms");
            System.out.println("1. Selection Sort");
            System.out.println("2. Insertion Sort");
            System.out.println("3. Nearly Sorted");
            System.out.println("4. Shell Sort");
            System.out.println("5. Quick Sort");
            System.out.println("6. Merge Sort");
            System.out.println("7. Radix Sort");
        }
        // }
    }

    public void takeInput() {
        System.out.print("Enter the number of elements in the Array to be processed >>>>>> ");
        numberOfElements = input.nextInt();
        for (int i = 0; i < numberOfElements; i++) {
            System.out.print("Element at index " + i + ": ");
            elements[i] = input.nextInt();
        }
        System.out.println();
    }

    public void displayInput() {
        System.out.println("\nElements to be taken as inputs: [ ");
        for (int i = 0; i < numberOfElements; i++) {
            System.out.print(elements[i] + " ");
        }
        System.out.println("]");
    }

}