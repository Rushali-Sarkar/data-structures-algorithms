import java.util.*;

public class linearsearch {

    public static boolean search(ArrayList<Integer> arr, int element) {
        int size = arr.size();
        for (int i = 0; i < size; i++) {
            if (arr.get(i) == element)
                return true;
        }
        return false;
    }

    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        System.out.println("Enter the number of elements you want to enter");
        int size = ob.nextInt();
        int i = 1;
        while (i <= size) {
            System.out.println("Enter the number:");
            arr.add(ob.nextInt());
            i++;
        }
        System.out.println("Enter the element you want to search for");
        int element = ob.nextInt();
        boolean isPresent = search(arr, element);
        if (isPresent)
            System.out.println("The element is present in the list");
        else
            System.out.println("The element is not present in the list");
        return;
    }
}      
