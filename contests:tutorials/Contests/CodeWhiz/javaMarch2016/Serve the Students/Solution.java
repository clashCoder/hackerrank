import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Student{
   private int token;
   private String fname;
   private double cgpa;
   public Student(int id, String fname, double cgpa) {
      super();
      this.token = id;
      this.fname = fname;
      this.cgpa = cgpa;
   }
   public int getToken() {
      return token;
   }
   public String getFname() {
      return fname;
   }
   public double getCgpa() {
      return cgpa;
   }
}

/*  Input:
 *      n -> integer representing total number of events
 *      n lines of events , the event can either be ENTER name CGPA token (insert student in queue)
 *                              or SERVED (serve/remove the highest priority student from queue) , where
 *                              highest priority is based on highest CGPA, followed by ascending name,
 *                              followed by token order
 *  Constraints:
 *      2 <= n <= 1000
 *      0 <= CGPA <= 4.000 where CGPA is a real number
 *      1 <= tokeni <= 10^5 , where each tokeni is a unique integer
 *      2 <= |name| <= 30
 *  Output:
 *      print the students left on the queue after all 'n' events based on highest priority.
 */

public class Solution {
    
/*
 * Function merges two List of Student objects based on highest priority.
 */
public static List<Student> merge(List<Student> studentA, List<Student> studentB) {
    int lengthOfA = studentA.size();
    int lengthOfB = studentB.size();
    int mergerLength = lengthOfA + lengthOfB;
    
    int curIndexA = 0;
    int curIndexB = 0;
    //System.out.println(lengthOfA);
    //System.out.println(lengthOfB);
    //System.out.println(mergerLength);
    
    List<Student> merger = new ArrayList<Student>();
    
    if (lengthOfA == 0) {
        return studentB;
    }
    if (lengthOfB == 0) {
        return studentA;
    }
    
    while(mergerLength > merger.size()) {
        
        if (curIndexA >= lengthOfA) {
            int startOfB = curIndexB;
            for (int i = curIndexB; i < lengthOfB; i++) {
                merger.add(studentB.get(curIndexB));
                curIndexB++;
            }
            break;
        }
        
        if (curIndexB >= lengthOfB) {
            for (int i = curIndexA; i < lengthOfA; i++) {
                merger.add(studentA.get(curIndexA));
                curIndexA++;
            }
            break;
        }
        
        //System.out.println(curIndexA);
        double gpaOfA = studentA.get(curIndexA).getCgpa();
        double gpaOfB = studentB.get(curIndexB).getCgpa();
        
        String nameOfA = studentA.get(curIndexA).getFname();
        String nameOfB = studentB.get(curIndexB).getFname();
        
        int tokenOfA = studentA.get(curIndexA).getToken();
        int tokenOfB = studentB.get(curIndexB).getToken();
        
        
        if (gpaOfA > gpaOfB) {
            merger.add(studentA.get(curIndexA));
            curIndexA++;
        }
        else if (gpaOfA == gpaOfB) {
            int lexiCompAToB = nameOfA.compareTo(nameOfB);
            
            if (lexiCompAToB < 0) {
                merger.add(studentA.get(curIndexA));
                curIndexA++;
            }
            else if (lexiCompAToB == 0) {
                if (tokenOfA < tokenOfB) {
                    merger.add(studentA.get(curIndexA));
                    curIndexA++;
                }
                // tokenOfA > tokenOfB ....note in no situation should two different individuals
                // hold the same token
                else {
                    merger.add(studentB.get(curIndexB));
                    curIndexB++;
                }
            }
            // lexiCompAToB > 0 .... which means (nameOfA > nameOfB) 'lexicographically'
            else {
                merger.add(studentB.get(curIndexB));
                curIndexB++;
            }
        }
        // gpaOfA < gpaOfB
        else {
            merger.add(studentB.get(curIndexB));
            curIndexB++;
        }
    }
    
    return merger;
}    

/*
 * Function sorts a List of Student objects based on highest priority.
 */
public static List<Student> mergeSort(List<Student> students) {
    
    int numStudents = students.size();
    
    if (numStudents <= 1) {
        return students;
    }
    
    int mid = numStudents / 2;
    List<Student> leftStudentList = mergeSort(students.subList(0,mid));
    List<Student> rightStudentList = mergeSort(students.subList(mid,numStudents));
    //System.out.println(mid);
    //merge(leftStudentList, rightStudentList);
    return merge(leftStudentList, rightStudentList);
}
    
    
    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int totalEvents = Integer.parseInt(in.nextLine());
      String previousEvent = "";
        
      List<Student> listStudents = new ArrayList<Student>();
      while(totalEvents>0){
          String event = in.next().replaceAll("[^a-zA-z]","").toLowerCase();
          
          if (event.equals("enter")) {
              String name = in.next();
              //String gpaString = in.next();
              //String tokenString = in.next();
              double gpa = Double.parseDouble(in.next());
              int token = Integer.parseInt(in.next());
              
              Student student = new Student(token, name, gpa);
              listStudents.add(student);
              previousEvent = "enter";
          }
          if (event.equals("served")) {
              if (listStudents.size() > 0) {
                  if(!previousEvent.equals("served")) {
                     listStudents = mergeSort(listStudents);    
                  }
                  listStudents.remove(0);           //since properly sorted remove next Student served (1st in list)
              }
              /*for(Student s: listStudents) {
                  System.out.println(s.getFname());
              }
              System.out.println("");*/
              previousEvent = "served";
          }
          
          
          //System.out.println(event);
           //Complete your code
          //Student s = new Student(12, "name", 3.0);
          //listStudents.add(s);
           
          totalEvents--;
      }
        //System.out.println(listStudents.size());
        //List<Student> list = mergeSort(listStudents);
        
        
        if (listStudents.size() > 0) {
            for (Student s: listStudents) {
                System.out.println(s.getFname());
            }
        }
        else {
            System.out.println("EMPTY");   
        }
    }
}
