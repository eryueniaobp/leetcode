#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <string> backwardStack,forwardStack;
string command,current_web;
int main(){
    current_web="http://www.acm.org/";
    while (cin>>command,command[0]!='Q'){
        switch (command[0]){
            case'V':while (!forwardStack.empty()) forwardStack.pop();
                    backwardStack.push(current_web);
                    cin>>current_web;
                    cout<<current_web<<endl;
                    break;
            case'B':if (!backwardStack.empty()){
                        forwardStack.push(current_web);
                        current_web=backwardStack.top();
                        backwardStack.pop();
                        cout<<current_web<<endl;
                    }
                    else
                        cout<<"Ignored\n";
                    break;
            case'F':if (!forwardStack.empty()){
                        backwardStack.push(current_web);
                        current_web=forwardStack.top();
                        forwardStack.pop();
                        cout<<current_web<<endl;
                    }
                    else
                        cout<<"Ignored\n";
                    break;
        }
    }
    return 0;
}

