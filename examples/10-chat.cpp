#include "openai.hpp"
#include <iostream>
#include<string>
using namespace std;
void showMenu()//菜单
{
    cout << "**************" << endl;
    cout << "*1.咨询恋爱军师*" << endl;
    cout << "*0.退出恋爱军师*" << endl;
    cout << "**************" << endl;
}
void run()
{
    openai::start("sk-on-Jo5FAGExsug1vrAvXCQ", "", true, "https://agino.me/");

    int age;
    string job, gender, question;

    cout << "请输入年龄: ";
    cin >> age;

    cin.ignore();  // 清除输入流中的换行符

    cout << "请输入工作: ";
    getline(cin, job);

    cout << "请输入性别: ";
    getline(cin, gender);

    cout << "请输入对话内容: ";
    getline(cin, question);

    nlohmann::json data = R"(
    {
        "model": "gpt-3.5-turbo",
        "messages":
        [
            {"role": "system", "content": "你是一个恋爱高手."},
            {"role": "user", "content": ""}
        ],
        "max_tokens": 4096,
        "temperature": 0.5
    }
    )"_json;

    data["messages"][1]["content"] = "年龄：" + to_string(age) + "，工作：" + job + "，性别：" + gender + "，对话内容：" + question;

    auto chat = openai::chat().create(data);

    cout << "回复是:\n" << chat["choices"][0]["message"]["content"] << '\n';
    system("pause");
    system("cls");
}
int main() {
    int select = 0;

    while (true){
        showMenu();
    cin >> select;
    switch (select)
    {
    case 1://添加联系人
        run();
        break;
    case 0://退出通讯录
        cout << "欢迎下次使用" << endl;
        system("pause");
        return 0;
        break;
    }
}

system("pause");
return 0;
}

