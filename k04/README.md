# 課題4 レポート

bb35319058 吉村巧

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
27~40 IDのサンプルを入力
42~56 身長,性別のサンプルを入力
61~77 サンプルに基づきID,身長,性別を表示
79~81 サンプルにない場合にNo dataと表示

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment #20200721]
- 値を読み込んでいく時にNが初期化されずにずっと加算されているので、正しい値が読み込めていません。それぞれのwhile文の前でN=1と初期化をしてください。

- 尚、heights.csvは一行目がラベルとなっていますので、二行目からの読み込みとなるように修正をお願いします。
