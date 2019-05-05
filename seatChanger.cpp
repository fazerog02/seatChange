#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;



//文字列が数字かどうか判定する
bool IsNumber(string s){
    bool is_number = true;
    for(int i = 0; i < s.size(); i++){
        if(!isdigit(s[i])) is_number = false;
    }
    return is_number ? true : false;
}



int main(){


    //人数の処理
    string number_of_people_string;
    int number_of_people_int;
reinput_number_of_people_string:
    cout << "人数を入力してください" << endl;
    cout << ">>> ";
    cin >> number_of_people_string; //stringで受けておく
    if(!IsNumber(number_of_people_string)){
        //数字以外の場合は再入力させる
        cout << "ERROR: 数字を入力してください" << endl;
        goto reinput_number_of_people_string;
    }
    number_of_people_int = stoi(number_of_people_string); //stringで受けていたものをintに戻す


    //座席表の出席番号を-1で初期化しておく
    vector<int> field_of_seat(number_of_people_int);
    for(int i = 0; i < number_of_people_int; i++){
        field_of_seat[i] = -1;
    }


    //設定
    string selected_position_string, selected_seat_number_string;
    int selected_position_int, selected_seat_number_int;
    vector<int> selected_position_list, selected_seat_number_list;
    cout << "限定ランダムの設定(目が悪い人など)[endで終了]" << endl;
    cout << "席の番号" << endl;


    //席の番号表を表示する
    for(int i = 1; i <= number_of_people_int; i++){
        printf("%c%2d%c ", '[', i, ']');
        if(i % 6 == 0) cout << endl; //6個ずつで改行する
    }
    cout << endl;


    //限定でランダムに選ぶ席を指定する
    cout << "限定でランダムに選ぶ席を指定してください" << endl;
    while(1){
    reinput_selected_position_string:
        cout << ">>> ";
        cin >> selected_position_string; //stringで受けておく

        if(selected_position_string == "end"){
            //endと入力されたら画面をきれいにして終了する
            system("clear");
            break;
        }
        if(!IsNumber(selected_position_string)){
            //数字以外の場合は再入力させる
            cout << "数字を入力してください" << endl;
            goto reinput_selected_position_string;
        }
        selected_position_int = stoi(selected_position_string); //stringで受けていたものをintに戻す

        if(selected_position_int > number_of_people_int){
            //入力された座席の番号が存在しない場合は再入力させる
            cout << "ERROR: その座席は存在しません" << endl;
            goto reinput_selected_position_string;
        }

        selected_position_list.push_back(selected_position_int); //問題がないのでリストに座席の番号を追加する
    }


    //限定でランダムに選ぶ出席番号を指定する
    cout << "限定でランダムに選ぶ出席番号を指定してください" << endl;
    while(1){
    reinput_selected_seat_number:
        cout << ">>> ";
        cin >> selected_seat_number_string;

        if(selected_seat_number_string == "end"){
            //endと入力されたら画面をきれいにして終了する
            system("clear");
            break;
        }
        if(!IsNumber(selected_seat_number_string)){
            //数字以外の場合は再入力させる
            cout << "数字を入力してください" << endl;
            goto reinput_selected_seat_number;
        }

        selected_seat_number_int = stoi(selected_seat_number_string);//stringで受けていたものをintに戻す

        if(selected_seat_number_int > number_of_people_int){
            //入力された出席番号が存在しない場合は再入力させる
            cout << "ERROR: その出席番号は存在しません" << endl;
            goto reinput_selected_seat_number;
        }

        selected_seat_number_list.push_back(selected_seat_number_int); //問題がないのでリストに出席番号を追加する
    }


    //限定ランダムで先に座席を決める
    random_device random;
    int random_number;

    bool is_exist;

    for(int i = 0; i < selected_seat_number_list.size(); i++){
    retry_closed_random:
        is_exist = false;
        random_number = random() % selected_position_list.size(); //指定された座席からランダムで選ぶ
        if(field_of_seat[selected_position_list[random_number]-1] != -1) is_exist = true; //すでに選ばれているかどうか確認する
        if(is_exist){
            //すでに選ばれていたらもう一度指定された座席からランダムで選び直す
            goto retry_closed_random;
        } else {
            field_of_seat[selected_position_list[random_number]-1] = selected_seat_number_list[i]; //座席を決める
        }
    }


    //座席を決める
    for(int i = 0; i < number_of_people_int; i++){
        if(field_of_seat[i] != -1) continue; //すでに決めてあったらスキップする
    retry_random:
        random_number = (random() % number_of_people_int) + 1; //ランダムで出席番号を一つ選ぶ
        //すでに出席番号が使われていたらもう一度ランダムで出席番号を一つ選び直す
        for(int j = 0; j < number_of_people_int; j++){
            if(field_of_seat[j] == random_number) goto retry_random;
        }

        field_of_seat[i] = random_number; //座席を決める
    }


    //座席表を表示する
    cout << "Enterを押してスタート" << endl;
    //Enterの入力待ち
    while(getchar() != '\n');
    while(getchar() != '\n');

    //３秒カウントする
    for(int i = 3; i >= 1; i--){
        cout << i << endl;
        if(number_of_people_int <= 100)sleep(1);
    }
    cout << "GO!" << endl << endl;
    sleep(1);

    cout << "-------黒板--------" << endl << endl;
    //表を表示する
    for(int i = 0; i < number_of_people_int; i++){
        printf("%c%2d%c ", '[', field_of_seat[i], ']');
        if((i+1) % 6 == 0) cout << endl; //6個ずつで改行する
    }
    cout << endl << endl;
    cout << "FINISH!" << endl << endl;

    cout << "endで終了" << endl;
    string end;
    while(1){
        //endの入力待ち
        cin >> end;
        if(end == "end") break;
    }


    return 0;
}
