import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;


class Singleton{
    
    private static Singleton singleton = new Singleton();
    public String str;
    
    private Singleton() { 
        //str = new Singleton();
    }
    
    public static Singleton getSingleInstance() {
        return singleton;
    }
}
