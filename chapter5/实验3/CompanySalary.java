abstract class Employee {
   public abstract double earnings();
}
class YearWorker extends Employee {
   ������1�� //��дearnings()����
}
class MonthWorker extends Employee {
   ������2�� //��дearnings()����
}
class WeekWorker extends Employee {
   ������3�� //��дearnings()������
}
class Company {
   Employee[] employee;
   double salaries=0;
   Company(Employee[] employee) {
      this.employee=employee;
   }
   public double salariesPay() {
       salaries=0;
      ������4�� //����salaries��
       return salaries;
   }    
}
public class CompanySalary {
   public static void main(String args[]) {
      Employee [] employee=new Employee[29]; //��˾��29����Ա
      for(int i=0;i<employee.length;i++) {   //��Ա�򵥵طֳ�����
          if(i%3==0)
              employee[i]=new WeekWorker();
          else if(i%3==1)
              employee[i]=new MonthWorker();
          else if(i%3==2)
             employee[i]=new YearWorker();
      } 
      Company company=new Company(employee);
      System.out.println("��˾нˮ�ܶ�:"+company.salariesPay()+"Ԫ");
   }
}
