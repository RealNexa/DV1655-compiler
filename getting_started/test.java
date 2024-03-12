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

    int[] list;
    int q;

    public int hello(){
        a = 0;
        b = 10;
        c = 20;
        x = 0;
        if (x > 10) {
            a=2;
            if(a < 10) {
                b = 20;
            }
            else {
                c = 30;
            }
        }
        else {
            if(c == 10)
                c = 20;
            else
                c = 1000000000000000000000000000000;
        }

        x = 100; // ulfs siffra
        x = 100; // 
        return 1;
    }
}