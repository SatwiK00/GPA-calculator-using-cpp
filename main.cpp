#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib>

class GPA_calculator{
        std::vector<double> credits;
        std::vector<char> grade;
        int no_of_subjects;
        public:
        GPA_calculator(int no_of_subjects){
                this->no_of_subjects=no_of_subjects;
        }
        void get_inputs();
        double calculate_GPA();

};

void GPA_calculator::get_inputs(){
        std::cout<<"\nEnter Credit and Grade:"<<std::endl;
        for(int i=0;i<no_of_subjects;i++){
                double c=0;
                char g=' ';
                std::cin>>c>>g;
                credits.push_back(c);
                grade.push_back(g);
        }
}

double GPA_calculator::calculate_GPA(){
        char grade_ar[]={'F','E','D','C','B','A','S'};//Array Of Grades
        double  points_ar[]={0, 5, 6, 7, 8, 9, 10};//Array Of Points
        double sum_of_points=0;
        double total_credits=0;
        for(int i=0;i<no_of_subjects;i++){
                total_credits+=credits[i];
                for(int j=0;j<7;j++){
                        if(grade[i]==grade_ar[j]){
                                sum_of_points+=credits[i]*points_ar[j];
                                break;

                        }
                }
        }
        return (sum_of_points)/total_credits;
}


class CGPA_calculator{
        std::vector<double> credits_per_semester;
        std::vector<double> gpa_per_semester;
        int no_of_semesters;
        public:
        CGPA_calculator(int no_of_semesters){
                this->no_of_semesters=no_of_semesters;
        }
        void set_input();
        double calculate_CGPA();     
};

void CGPA_calculator::set_input(){
        std::cout<<"\nEnter Credits and gpa per semester:"<<std::endl;
        for(int i=0;i<no_of_semesters;i++){
                        double tc=0;
                        double gpa=0;
                        std::cin>>tc>>gpa;
                        credits_per_semester.push_back(tc);
                        gpa_per_semester.push_back(gpa);
                }  
} 

double CGPA_calculator::calculate_CGPA(){
        double total_credit_points=0.0;
        double overall_credits=0.0;
        for(int i=0;i<no_of_semesters;i++){
                total_credit_points+=credits_per_semester[i]*gpa_per_semester[i];
                overall_credits+=credits_per_semester[i];
        }
        return (total_credit_points/overall_credits);
}

int main(){
        int x=0;
        int n_cgpa=0;
        int n_gpa=0;
        do{
                std::cout<<"\n-----MENU--------"<<std::endl;
                std::cout<<"1.CGPA calculator"<<std::endl;
                std::cout<<"2.GPA calculator"<<std::endl;
                std::cout<<"3.Exit"<<std::endl;
                std::cout<<"Enter your choice:";
                std::cin>> x;
                switch(x){
                        case 1:{
                        std::cout<<"\n--CGPA Calculator--"<<std::endl;
                        std::cout<<"Enter no. of semesters:";
                        std::cin>>n_cgpa;
                        CGPA_calculator obj_CGPA(n_cgpa);
                        obj_CGPA.set_input();
                        std::cout<<"\nCGPA is: "<<std::setprecision(3)<<obj_CGPA.calculate_CGPA()<<std::endl;
                        break;}

                        case 2:{
                        std::cout<<"\n--GPA Calculator--"<<std::endl;
                        std::cout<<"Enter no. of subjects:"<<std::endl;
                        std::cin>>n_gpa;
                        GPA_calculator obj_GPA(n_gpa);
                        obj_GPA.get_inputs();
                        std::cout<<"\nGPA is:"<<std::setprecision(3)<<obj_GPA.calculate_GPA()<<std::endl;
                        break;}

                        case 3:
                        std::cout<<"Exiting the program"<<std::endl;
                        exit(0);
                        break;

                        default:
                        std::cout<<"Invalid choice input"<<std::endl;
                        break;
                }
          }while (1); 
}   
