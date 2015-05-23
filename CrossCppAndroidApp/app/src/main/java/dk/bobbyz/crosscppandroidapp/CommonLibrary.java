package dk.bobbyz.crosscppandroidapp;

/**
 * Created by Bobby on 20-05-2015.
 */
public class CommonLibrary {
    private long ptr;

    public CommonLibrary() {
        ptr = this.initCommonLibrary();
    }

    public native long initCommonLibrary();
    public native void destructCommonLibrary(long ptr);

    // declare native method
    public native String hello(String world);

    // load DLL that contains static method
    static {
        System.loadLibrary("CommonLibrary");
    }
}