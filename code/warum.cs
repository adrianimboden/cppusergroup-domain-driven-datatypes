using System;
using System.Collections.Generic;

public class HelloWorld
{
  public static List<int> cache;
  public static void doSomething(List<int> list) { //null?
    list.Add(5);  // no language-level const
    cache = list; // shareability is a type-design decision
  }
  
  public static void main(String[] args)
  {
    List<int> my_list = new List<int>();
    my_list.Add(1);
    doSomething(my_list);
    doSomething(null);
  }
}

