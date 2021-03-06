# TECSUnit引継ぎ
まずは[TECSUnit](https://qiita.com/seito-zoso/items/14834c5c426fa03e0fb7)を確認してください．

[Github](https://github.com/seito-zoso/TECSUnit)からクローン．
これはEV3ベースでの実装です．まずはこれを別のデバイスに移すところからやるといいかもしれません．

# ファイルの構成説明

コンポーネント図で登場するセルを構成するファイルを説明します．

- TaskMainセル：下３つのセルを制御してテストを行うセル
- JSMNセル：JSONからテストターゲットを判別する
- TECSInfoセル：テストターゲットの情報を取得する
- TECSUnitセル：動的結合しテストを行う

## メインファイル
大元のファイルはhr_tecs/workspace/TESUnit/TECSUnit.cdl
コンポーネント図のセルが定義されています．
src/tTaskMain.c が TaskMainセルのセルタイプコードです．

## テストターゲットファイル
target/target.cdl　と src/target.c がTECSUnitのテスト対象とします．
target.jsonにはこれをテストするように書いてます．

## ヘッダーファイル
src/unit_struct.h　
引数構造体・条件構造体の実装のための構造体、共用体を実装したファイル．

## プラグインファイル
そもそもプラグインファイルとは？ってなるのであればTECSdocsで調べてください．
簡単にいうとセル・セルタイプ・セルタイプコードなどをtecsgenに通した際に自動作成するためのrubyコードです．
手書きで作成しきれないモノを作成するのに使います．
（rubyの書き方をある程度勉強する必要があります．）

コンポーネント図のセル（JSMN,TECSInfo,TECSUnit）はテストターゲットに依存したものになるのでプラグインコードで自動作成する必要があります．
それぞれの所在と説明は以下の通り、ファイルにコメントアウトに説明書いてるので目を通してください．

### １．JSMNプラグイン
/hr-tecs/tecsgen/tecsgen/tecslib/plugin/JSMNPlugin.rb

JSMNセルタイプ "gen/tmp_JSMNPlugin_0.cdl" とセルタイプコード "gen/tJSMN.c" を自動生成する．

### ２．TECSInfoプラグイン
/hr-tecs/tecsgen/tecsgen/tecslib/plugin/TECSInfo.rb

TECSInfoセル "gen/tmp_TECSInfoPlugin_post_code.cdl" とセルタイプコード "gen/nTECSInfo_*.c" を自動生成する．

### ３．TECSUnitプラグイン
/hr-tecs/tecsgen/tecsgen/tecslib/plugin/TECSUnitPlugin.rb

TECSUnitセルタイプ "gen/tmp_TECSUnitPlugin_0.cdl" とセルタイプコード "gen/tTECSUnit.c" を自動生成する．


### ※プラグインコードでのファイルへの出力方法
```:Plugin.rb
file.print <<EOT
書きたいコード（変数なども#{}で記載できる）
EOT
```
fileは引数でもってきたやつ．
EOTは始点終点を判別するキーワードなので多分どんなワードでもいい．
ただ２個目のEOTは左端に寄せて書く必要あり．（空白を入れちゃダメ）

## jsmnフォルダ
jsonを読み取る機能[jsmn](https://mattn.kaoriya.net/software/lang/c/20120822011026.htm)をダウンロードしたものをそのまま入れています．
JSMNプラグインに非受け口関数に実装したのでもう消していいかも．確認してみてください．


# 今後について
TODOをすこしまとめてみました．使ってみて思うことあればどんどん改善してください．

### 引数・条件用の構造体について
jsonで記載された情報を動的に読み取ってテストするために、引数を構造体と共用体（unit_struct.hで定義）で実装しています．事前・事後条件も同じです．（２つを分けているのは構造体の第一メンバが異なるためです）
しかし、この実装が良いようには思えないです．

- 引数を何個使うのかCDLコード（TECSUnit.cdl）で決め打ちしている（属性のDIM）．
- 共用体を用いてメモリの無駄を減らしたつもりですがどうなんでしょうか．配列の大きさはメモリが同じになるように揃えているが、それもどうなのか．
- unit_struct.h は手書きしていて、もしここに記載されていない型が存在すればエラーがでます．もしtypedefされている引数が型があれば確定でエラーが出ます．追記する必要がある．

パッと思いつく別の方法は、voidポインタにmallocしてキャスト、インクリメントりする方法ですが良い案かはわかりません．．色々試してください．
実装を変えた場合はJSMNとTECSUnitのプラグインコードから構造体を用いた出力部分を変更する必要があります．

### out指定子
今の実装ではout指定子付きの引数の結果を見れないです．TECSUnitPlugin.rbでTODOとしているのでそこをみてください．今はvoid型のセル変数 "* VAR_data" をmallocしてキャスト・インクリメントすることで実装してみましたが、動作未確認です．

### pre-condの改善
CellA -> CellB として、CellAをテストするとする．pre-condでCellB側の振舞いを書けるようにすればピュアな単体テストといえる．
（precondにセル名を指定できるようにすればいい）
また、今はpre-condの値でCellの値が完全に書き換わってしまい、次のテストで影響あり．毎回pre-condで戻してあげる仕様にする．



### 他のデバイスに簡単に移植できるように
現状はEV3用ですので、他のデバイスに移植してみてください．
変更するべき点はjsonコードの読み込み箇所とTaskMainで実装しているUIの部分です．
TECSUnitはコンポーネント実装なので変えるべきところはすくないとは思いますが、JSMNプラグインコードをいじらなければいけないのです．あんまし良くない実装なので、コンフィグレーションで簡単に変更できるように改善してください．

### TaskMainのテスト方法・出力結果
TaskMainでひとつひとつEnterボタンをおして確認していく仕様です．
テスト結果がLCDで確認刷るだけです．
もっと一気にテストして、テスト結果をSDやシリアルを通して出力できるようにしてください．

### テスト評価
返り値と期待値を ==演算子で評価しているだけです．pre_cond, post_condでも同様に評価してますが十分でないかもしれません．

### 結合テスト
現状はセルの単体テストです．結合テストできるように発展させてください．
一応、「あるセルをテストした際、テスト対象セルの内部情報は次のテストケースでも保持される（この仕様はむしろ単体テストとしてはよくないのかも）」、「あるセルをテストで呼び出したらそのセルが呼び出したセルも呼び出される」という結合テスト的側面はあります．

「out指定子で得た値を次のテストで流用できるようにしたい」という意見もあります．これができれば結合テストに発展できると思います．
