import java.util.*;

public class wall_paint
{
  public static void main(String args[])
 {
  Scanner input = new Scanner(System.in);
  
  System.out.print("Enter the height (feet): ");
  double height;
  height = input.nextDouble();
  
  System.out.print("Enter the width (feet): ");
  double width;
  width = input.nextDouble();
  
  double area;
  area = height * width;
  
  final double GALLONS_PER_SQUARE_FEET = 150.0;
  
  double gallons;
  gallons = area/GALLONS_PER_SQUARE_FEET;
  
  System.out.println("The amount of paint is " + gallons + " gallons.");
  
 }
}
