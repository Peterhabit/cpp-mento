#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::cout;
class Cat {
private: //생략가능
	int age;
	char name1[20];
	// const char* name1; //A
public:
	Cat(int age, const char* n) {
		this->age = age;
		strcpy(name1, n); // name1=n; //A
		cout << name1 << "고양이 객체가 만들어졌어요.\n";
	}
	~Cat() { cout << name1 << "객체 바이\n"; };
	int getAge();
	const char* getName();
	void setAge(int age);
	void setName(const char* pName);
	void meow();
};
int Cat::getAge() {
	return age;
}
void Cat::setAge(int age) {
	this->age = age;
}
void Cat::setName(const char* pName) {
	strcpy(name1, pName);
	//strcpy(대상주소, 원본주소);
	//strcpy_s(대상주소, 대상의길이, 원본주소);
	//name1=pName; //A
}
const char* Cat::getName() {
	return name1;
}
void Cat::meow() {
	cout << name1 << "고양이가 울어요\n";
}
int main() {
	Cat nabi(1, "나비"), yaong(1, "야옹"), * pNabi;
	cout << nabi.getName() << " 출생 나이는 " << nabi.getAge() << "살이다.\n";
	cout << yaong.getName() << " 출생 나이는 " << yaong.getAge() << "살이다.\n";
	pNabi = &nabi;
	cout << pNabi->getName() << " 출생 나이는 " << pNabi->getAge() << "살이다.\n";
	nabi.setName("Nabi");
	nabi.setAge(3);
	cout << nabi.getName() << " 나이는 " << nabi.getAge() << "살이다.\n";
	yaong.meow();
	nabi.meow();
	return 0;
}
//나비고양이 객체가 만들어졌어요.
//야옹고양이 객체가 만들어졌어요.
//나비 출생 나이는 1살이다.
//야옹 출생 나이는 1살이다.
//나비 출생 나이는 1살이다.
//Nabi 나이는 3살이다.
//야옹고양이가 울어요
//Nabi고양이가 울어요
//야옹객체 바이
//Nabi객체 바이v