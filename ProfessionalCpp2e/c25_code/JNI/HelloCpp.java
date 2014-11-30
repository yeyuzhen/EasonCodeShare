public class HelloCpp {

    static {
        System.loadLibrary("hellocpp");
    }

    // This will be implemented in C++
    public native void callCpp();

    public static void main(String[] args)
    {
        System.out.println("Hello from Java!");

        HelloCpp cppInterface = new HelloCpp();
        cppInterface.callCpp();
    }
}
