public class LittleTest {
    public static void main(String[] a) {
        System.out.println(new MyClass());
    }
}

class MyClass {

    int a;
    int b;
    int c;
    int x;

    public int hello(){
        a = 0;
        b = 10;
        c = 20;

        x = 5;

        if (x < 1) {
            a = b;
        }
        else {
            a = c;
        }

        x = 100;

        return 1;
    }
}