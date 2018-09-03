import java.lang.*;
import java.util.*;
public class Palabra{
  public String cadena;
  int lim=175760;
int i = 0;
  
  Palabra(String cad){
    cadena= new String(cad);
  }
  
  void ObtenerCad(){
    for(i=0;i<lim;i++){
      cadena=cadena + (char)(Math.random()*(90-65 + 1) + 65 );
    }
  }
  
  void Imprimir(){
    System.out.println(cadena);
  }  
  
  int Buscar(){
      int count = 0;
      for(int i = 0;i<cadena.length();i++){
          try{
          if (cadena.charAt(i)=='I') {
              
              if (cadena.charAt(i+1)=='P') {
                  
                  
                  if (cadena.charAt(i+2)=='N') {
                      count++;
                      continue;
                  }
                  
              }
              
          }
          }catch(Exception e){}
      }
      return count;
  }
    public static void main(String[] args){
    Palabra obj=new Palabra(" ");
    obj.ObtenerCad();
    int a = obj.Buscar();
    }
}


