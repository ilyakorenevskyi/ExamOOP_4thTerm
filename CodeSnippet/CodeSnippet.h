#pragma once
#include <string>
class CodeSnippet{
	friend class CodeBuilder;
	std::string company;
	std::string project;
	std::string component;
	std::string class_name;
	std::string method;
public:
	CodeSnippet();
	/*CodeSnippet(std::string company_, std::string proj_, std::string compon_, std::string class_, std::string meth_) :company(company_), project(proj_), component(compon_), class_name(class_), method(meth_) {};
	std::string getCompany() { return company; };*/
	std::string setCompany(std::string name) { this->company = name; }
	std::string getProject() { return project; };
	std::string setProject(std::string name) { this->project = name; };
	std::string getComponent() { return component; };
	std::string setComponent (std::string name) { this->component = name; };
	std::string getClass() { return class_name; };
	std::string setClass(std::string name) { this->class_name = name; };
	std::string getMethod() { return method; };
	std::string setMethod(std::string name) { this->method = name; };
};
class CodeBuilder {
	CodeSnippet* code;
public:
	void Reset() {
		this->code = new CodeSnippet();
	}
	void setCompany(std::string data) {
		this->code->company = data;
	}
	void setProject(std::string data) {
		this->code->project = data;
	}
	void setComponent(std::string data) {
		this->code->component = data;
	}
	void setClass(std::string data) {
		this->code->class_name = data;
	}
	void setMethod(std::string data) {
		this->code->component = data;
	}
	CodeSnippet* getCode() {
		CodeSnippet* res = code;
		this->Reset();
		return res;
	}

};
