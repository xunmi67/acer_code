#include <string>
using std::string;
const string &shorter_string(const &str1,const $str2){
    return str1.size()<=str2.size()?str1:str2;
}
int main(int agn,char **agv){
    string s1 = "abcd";
    string s2 = "abc";
    string s3 = shorter(s1,s2);
    return 0;
}


