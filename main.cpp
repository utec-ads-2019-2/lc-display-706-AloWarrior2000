#include <iostream>
#include <vector>

using namespace std;

vector<int> str_to_intarr(const string& F){
    vector<int> arr;
    for (char i : F) {
        arr.push_back(int(i) - 48);
    }

    return arr;
}


void print_horizontal(int times, bool seen){
    if (seen) {
        cout << " ";
        for (int i = 0; i < times; ++i) {
            cout << "-";
        }
        cout << " ";
    } else {
        for (int i = 0; i < times+2; ++i) {
            cout << " ";
        }
    }
}

void print_vecrtical(int times, bool left, bool right){
        if (left) cout << "|";
        else cout << " ";
        for (int j = 0; j < times; ++j) {
            cout << " ";
        }
        if (right) cout << "|";
        else cout << " ";
}

void print_upper(const vector<int>& numbers, int size){
    bool started = false;
    for (int number : numbers) {
        if (started) cout << " ";
        switch(number){
            case 0:
            case 2:
            case 3:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                print_horizontal(size,true);
                break;
            case 1:
            case 4:
                print_horizontal(size,false);
                break;
            default:
                break;
        }
        started = true;
    }
    cout << endl;
}

void print_semicenter(bool upper, const vector<int>& numbers, int size){
    bool started = false;
    for (int i = 0; i < size; ++i) {
        started = false;
        for (int number : numbers) {
            if (started) cout << " ";
            switch (number) {
                case 0:
                case 8:
                    print_vecrtical(size, true, true);
                    break;
                case 1:
                case 3:
                case 7:
                    print_vecrtical(size, false, true);
                    break;
                case 2:
                    print_vecrtical(size, !upper, upper);
                    break;
                case 4:
                case 9:
                    print_vecrtical(size, upper, true);
                    break;
                case 5:
                    print_vecrtical(size, upper, !upper);
                    break;
                case 6:
                    print_vecrtical(size, true, !upper);
                    break;
                default:
                    break;

            }
            started = true;
        }
        cout << endl;
    }
}

void print_center(const vector<int>& numbers, int size){
    bool started = false;
    for (int number : numbers) {
        if (started) cout << " ";
        switch(number){
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 9:
                print_horizontal(size,true);
                break;
            case 0:
            case 1:
            case 7:
                print_horizontal(size,false);
                break;
            default:
                break;
        }
        started = true;
    }
    cout << endl;
}

void print_lower(const vector<int>& numbers, int size){
    bool started = false;
    for (int number : numbers) {
        if (started) cout << " ";
        switch(number){
            case 0:
            case 2:
            case 3:
            case 5:
            case 6:
            case 8:
            case 9:
                print_horizontal(size,true);
                break;
            case 1:
            case 4:
            case 7:
                print_horizontal(size,false);
                break;
            default:
                break;
        }

        started = true;
    }
    cout << endl << endl;
}

void printerLCD(int S, string N){
    vector<int> by_nums = str_to_intarr(N);
    print_upper(by_nums, S);
    print_semicenter(true, by_nums, S);
    print_center(by_nums, S);
    print_semicenter(false, by_nums, S);
    print_lower(by_nums, S);
}

int main() {
    int s;
    string n;
    cin >> s >> n;
    while ( s!=0 or n!="0" ){
        printerLCD(s,n);
        cin >> s >> n;
    }
    return 0;
}
