#ifndef _EXAMINEE_H_
#define _EXAMINEE_H_

#include <string>

using namespace std;

struct Examinee {
	string id;
	float math;
	float literature;
	float physic;
	float chemistry;
	float biology;
	float history;
	float geography;
	float civic_education;
	float natural_science;
	float social_science;
	float foreign_language;
};

int DetectComma(string line, int prev);
Examinee ReadExaminee(string lineInfo);

#endif // _EXAMINEE_H_
