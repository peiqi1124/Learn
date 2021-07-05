// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
using namespace std; //编译指令和命名空间
#include <Windows.h>
#include <iostream>

int main()
{
    HWND h = FindWindowA("MainWindow",NULL);
    cout << h << endl;
    SetWindowTextA(h, "my name is porter!");
    DWORD pid = NULL, tid = NULL;
    tid=GetWindowThreadProcessId(h, &pid);
    cout << hex << tid << endl;
    cout << pid << ":" << &pid << endl;
    HANDLE hProcess=OpenProcess((DWORD)PROCESS_ALL_ACCESS,0, pid);
    cout << hProcess << endl;
    int setData = NULL;
    int getData = NULL;
    //cin >> setData;
    BOOL id = ReadProcessMemory(hProcess, (LPVOID)0x159ECCA8, &getData, 4, 0);
    cout << hex << getData << endl;
    cout << *dec <<getData << endl;
    cin >> setData;
    BOOL id_1 = WriteProcessMemory(hProcess,(LPVOID)0x159ECCA8,&setData,4,0);

    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
