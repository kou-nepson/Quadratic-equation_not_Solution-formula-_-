//
//  main.c
//  Quadratic equation_not_Solution formula
//
//  Created by 杉山航 on 2017/09/06.
//  Copyright © 2017年 杉山航. All rights reserved.
//

#include <stdio.h>

int main() {
    
    double a, b, c; //係数の変数
    
    double brackets_in_num;  //完全平方式の時に使用する変数
    
    double answer1, answer2; //解の変数
    
    double num_get; //平方根の近似値を求める時に使う変数
    
    double root_num = 0.0; //平方根の近似値の答えを格納する変数
    
    double root_in_num = 0.0; //平方根の中身の変数
    
    double tmp_a, tmp_b, tmp_c; //a,b,cをそのまま使わずに実行するために用意する変数
    
    double add_num; //完全平方式の時に追加する数字を
    int i; //ループ文のカウンタ
//    double root_num;
    
    printf("ax^2+bx+cのa,b,cの部分を入力してください。\n"); //入力を促す
    
    printf("a = "); //aの入力を促す
    scanf("%lf", &a); //aを読み込む
    
    printf("b = "); //bの入力を促す
    scanf("%lf", &b); //bを読み込む
    
    printf("c = "); //cの入力を促す
    scanf("%lf", &c); //cを読み込む
    
    tmp_a = a; //tmp_aにaを代入
    tmp_b = b; //tmp_bにbを代入
    tmp_c = c; //tmp_cにを代入
    
    //両辺をaの係数で割る
    tmp_a /= a;
    tmp_b /= a;
    tmp_c /= a;
    
    printf("\n %fx^2 %fx %f = 0\n", tmp_a, tmp_b, tmp_c);
    
    tmp_c *= -1; //cを移項
    
    printf("\n %fx^2 %fx  = %f\n", tmp_a, tmp_b, tmp_c);
    
    //完全平方式を実行
    brackets_in_num = tmp_b / 2; //かっこの中に半分にしたbを入れる
    
    add_num = brackets_in_num * brackets_in_num; //両辺に追加する変数にかっこの中の数を二乗した数を代入
    
    printf("\n %fx^2 %fx + %f  = %f + %f\n", tmp_a , tmp_b ,add_num, brackets_in_num, add_num);
    
    printf("\n (x %f)^2  = %f + %f\n", brackets_in_num, tmp_c, add_num);
    
    tmp_c += add_num; //右辺に追加
    
    printf("\n (x %f)^2  = %f\n", brackets_in_num, tmp_c);
    
    root_in_num = tmp_c; //右辺の平方根を求めるためにcを違う変数に格納
    
    //完全平方式終了
    
    num_get = 1.0; //ルートの近似値を求めるために使用する変数に1.0を代入
    //ルートの近似値を求める
    for (i = 1; i <= 7; i++) {
        //ルートの近似値の二乗がルートの中の数字を超えるまでのループ
        while (root_num * root_num <= root_in_num) {
            root_num += num_get; //ループの条件に合うまで1を追加し続ける
        }
        root_num -= num_get; //ループを抜けた時は一つ大きいので1を引く
        num_get /= 10.0; //足す数を10/1にする
        //ループ終了（これを7回繰り返す）
    }
    //ルートの近似値を求めるのは終了
    
    
    printf("\nx %f = ±%f\n", brackets_in_num, root_num);
    
    // かっこの中の数（元はb）を移項
    brackets_in_num *= -1;
    
    printf("\nx = %f ±%f\n", brackets_in_num, root_num);

    //二つの解を計算（ルートがプラスとマイナスなので引く解と、足す解が存在する）
    answer1 =  brackets_in_num + root_num; //足す解を計算
    answer2 = brackets_in_num - root_num; //引く解を計算
    
    //答えを出力
    printf("\n解　＝　%f , %f\n" ,answer1 , answer2);
    
}
