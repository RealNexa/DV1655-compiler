public class DanglingElse {
    public static void main(String[] a) {
        System.out.println(new AST().TestIfElse());
    }
}

class AST {

    public int TestIfElse() {
        boolean A;
        boolean B;
        A = false;
        B = true;
        // The following if-statements should generate the same tree.
        if (123==32)
            if (B)
                B = true;
            else
                B = false;
        
        C = 1; // ADDED FOR DEMONSTRATION OF SCOPE

        if (A) {
            if (B)
                B = true;
            else
                A = false;

            C = 1; // ADDED FOR DEMONSTRATION OF SCOPE
        }

        return 1;
    }

}
