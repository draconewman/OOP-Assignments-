#include<iostream>
#include<cstring>
using namespace std;
#define book_limit 10000
#define copy_limit 10000
#define student_limit 1000
#define faculty_limit 100

class Book
{
	protected:
		int book_id, num=0, price;
		string title, author publisher;
		int serial_number[copy_limit];
	public:
		void get_data();
		bool check(int p);
		void add(int p);
		void del(int p);
		friend class Library;		
};

class Library
{
	protected: 
		Book list[book_limit];
		int count=0;
	public:
		bool empty();
		bool full();
		void new_book(int book_id);
		int position(int book_id);
		bool present(int book_id, int serial_number);
		void add_copy(int book_id, int serial_number);
		void delete_copy(int book_id, int serial_number);
};

class Member
{
	protected:
		int id, issue;
		string name, address, email;
	public:
		void get_data();
	friend class Student;
	friend class Faculty;
};

class Student: public Member
{
	protected:
		Member arr_student[student_limit];
		int limit=0;
	public:
		bool full();
		void add_student();
		int check_student(int id);
};

class Faculty: public Member
{
	protected:
		Member arr_faculty[faculty_limit];
		int limit=0;
	public:
		bool full();
		void add_faculty();
		int check_faculty(int id);
};

class Transaction
{
	private:
		int member_id, book_id, serial_number;
		char member_type, transaction_type;
	public:
		void get_data();
};

int main()
{
	
}
















