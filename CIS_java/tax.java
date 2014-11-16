import java.util.*;

public class tax
{
  public static void main(String args[])
 {
  Scanner input = new Scanner(System.in);
  
  System.out.print("Enter the Gross Income ($) : ");
  double grossIncome;
  grossIncome = input.nextDouble();
  
  System.out.print("Enter the number of Dependents: ");
  double numOfDependents;
  numOfDependents = input.nextDouble();
    
  final double TAX_RATE = 0.02;
  
  final double STANDARD_DEDUCTION = 10000.0;
  
  final double DEPENDENT_DEDUCTION = 2000.0;
  
  double depend_deduction;
  depend_deduction = DEPENDENT_DEDUCTION * numOfDependents;
  
  double newGross;
  newGross = grossIncome - (depend_deduction +STANDARD_DEDUCTION) ;
  
  double incomeTax;
  incomeTax = newGross * TAX_RATE;
  
  double grossIncomeAfterTax;
  grossIncomeAfterTax = grossIncome - incomeTax;
  
  System.out.println("Your gross income is $" + grossIncome);
  System.out.println("The numbder of dependents are: " + numOfDependents + "dependents.");
  System.out.println("Your gross income is $" + grossIncome);
  System.out.println("Your Income Tax is $" + incomeTax);
  System.out.println("Your gross income after Income Tax is $" + grossIncomeAfterTax);
 }
}
