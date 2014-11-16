import java.util.*;

public class lab61
{
  public static void main(String args[])
 {
  Scanner input = new Scanner(System.in);
  
  System.out.print("How many hours did you work this week?: ");
  int hours;
  hours = input.nextInt();
  
  System.out.print("What is your hourly rate? ($) : ");
  double hourlyRate;
  hourlyRate = input.nextDouble();
  
  final double WORK_DAY = 40;
  
  if(hours > WORK_DAY) {
    double overRate;
    overRate = (WORK_DAY * hourlyRate) + ((hours - WORK_DAY) * (hourlyRate * 1.5));
    System.out.println("You weekly gross pay is $" + overRate);
  
  }else{
    double payRate;
    payRate = hours * hourlyRate;
    System.out.println("You weekly gross pay is $" + payRate);
    }
   }
 }
