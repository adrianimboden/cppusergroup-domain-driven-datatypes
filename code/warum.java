import java.util.ArrayList;

public class HelloWorld
{
  static ArrayList<Integer> cache;
  static void doSomething(ArrayList<Integer> list) { // null?
    list.add(5);  // no language-level const
    cache = list; // (almost) everything is always shared 
  }
  
  public static void main(String[] args)
  {
    final ArrayList<Integer> my_list = new ArrayList<>();
    my_list.add(1);
    doSomething(my_list);
    doSomething(null);
  }
}

