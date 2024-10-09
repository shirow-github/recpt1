# recpt1 (shirow-github Version)

*Current Version:* 1.2.12

PT1/PT2/PT3をLinuxで使う為の録画ツール(shirow-github版)  
※こちらはフォーク版ですのでご注意下さい。

####  ◎recpt1について
  - recpt1(本家)：http://hg.honeyplanet.jp/pt1/
  - recpt1(フォーク元)：https://github.com/stz2012/recpt1
####  ◎ドライバーについて
  - PT1/PT2：http://sourceforge.jp/projects/pt1dvr/
  - PT3：https://github.com/m-tsudo/pt3/
  - PX4/PX5/PX-MLT：https://github.com/nns779/px4_drv/
####  ◎その他ソフトウェア
  - libarib25(shirow-github版)：https://github.com/shirow-github/libarib25/
  - libpcsclite-bcas(shirow-github版)：https://github.com/shirow-github/libpcsclite-bcas/

----
##  インストール方法
#### ◎recpt1
```bash
$ cd recpt1/recpt1
$ ./autogen.sh
$ ./configure --enable-b25 ※libpcsclite-bcasを使用する場合は、--enable-softcas
$ make
$ sudo make install
```
#### ◎PT1/PT2ドライバー(DKMS)
```bash
$ cd recpt1/driver-pt1
$ sudo ${SHELL} ./dkms.install
$ sudo reboot
```
> [!WARNING]
> なお「dkms.install」実行後は、使用するシステムを必ず再起動して下さい。

##  アンインストール方法
#### ◎recpt1
```bash
$ cd recpt1/recpt1
$ sudo make uninstall
```

#### ◎PT1/PT2ドライバー(DKMS)
```bash
$ cd recpt1/driver-pt1
$ sudo ${SHELL} ./dkms.uninstall
$ sudo reboot
```
> [!WARNING]
> なお「dkms.uninstall」実行後は、使用するシステムを必ず再起動して下さい。

##  使用方法
```bash
$ recpt1 録画するチャンネル番号 録画秒数 出力先ファイル名

で、録画されます。

詳しいオプションはrecpt1 --helpをご覧下さい。
```
----
## チャンネル番号 (2024年7月3日現在)
13-62: Terrestrial Channels

BS01_0: BS朝日  
BS01_1: BS-TBS  
BS01_2: BSテレ東  
BS03_0: WOWOWプライム  
BS03_1: BSアニマックス
BS05_0: WOWOWライブ  
BS05_1: WOWOWシネマ  
BS07_0: BS朝日 4K  
BS07_1: BSテレ東 4K  
BS07_2: BS日テレ 4K  
BS09_0: BS11  
BS09_2: TwellV  
BS11_0: 放送大学  
BS11_1: BS釣りビジョン  
BS13_0: BS日テレ  
BS13_1: BSフジ  
BS15_0: NHK BS  
BS15_1: スターチャンネル  
BS17_0: NHK BSプレミアム 4K  
BS17_1: BS-TBS 4K  
BS17_2: BSフジ 4K  
BS19_0: J SPORTS 4  
BS19_1: J SPORTS 1  
BS19_2: J SPORTS 2  
BS19_3: J SPORTS 3  
BS21_0: WOWOWプラス  
BS21_1: 日本映画専門チャンネル  
BS21_2: グリーンチャンネル  
BS23_0: ディズニーチャンネル  
BS23_1: BSよしもと  
BS23_2: BSJapanext  
BS23_3: BS松竹東急  

C13-C63: CATV Channels

CS2-CS24: CS Channels

----
##  動作確認環境
Ubuntu 22.04.4 LTS GNU/Linux  
Linux 6.5.0-35-generic SMP x86_64

## Special Thanks
2chの「Linuxでテレビ総合」スレッドの皆様
