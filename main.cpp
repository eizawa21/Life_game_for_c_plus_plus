#include <iostream>
#include <unistd.h> //実行中に処理を一時停止するために使う。
#include "life_game.h" //自作のヘッダーを読み込んでいる。

using namespace std;

int main(){
    int cell_density; //セルの密度を決める変数。
    int generation; //セルの世代を保存する。

    cout << "セルの密度を(0％〜100％)の間で入力してください。" << endl;
    cin >> cell_density;

    life_game lif1(cell_density); //オブジェクトを生成して、引数にセルに密度を渡すことで初期のセルの密度を決める。
    lif1.set_calc_arr(); //計算用の２次元配列に現世代のセルの状態を渡す。
    system("clear"); 

    cout << "----------------------------------------Conway's Game of Life for C++----------------------------------------" << endl; 

    lif1.show_cell(); //0世代目のセルとフィールドを描画する。

    cout << "Generation:0" << endl;


    cout << "何世代まで実行しますか？" << endl;
    cin >> generation; //入力された数値の分だけセルの世代が進行する。

    for(int i = 1;i < generation+1;i++){
        lif1.set_calc_arr(); //現世代のセルを計算用の２元配列に挿入する。
        lif1.count_cell(); //セルの状態を計算して、次世代のセルとフィールドを状態を決める。
        
        usleep(0.1 * 1000000); //実行の一時中断、これはマイクロ秒単位なので、左側の数値が0.5なら0.5秒を意味する。
        system("clear"); //出力されたセルと描画フィールドをクリアする。

        cout << "----------------------------------------Conway's Game of Life for C++----------------------------------------" << endl; 
        lif1.show_cell(); //セルとフィールドを描画する。
        cout << "Generation:" << i << endl; //世代カウンター、

    }

    return 0;

}