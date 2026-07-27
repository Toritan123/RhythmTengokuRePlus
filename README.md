
# リズム天国リプラス

![リズム天国リプラス](media/rtp.png?raw=true "リズム天国リプラス")

これはGBAゲームである「リズム天国」の非公式機能追加プロジェクト「リズム天国プラス」の非公式継続プロジェクト「リズム天国リプラス」です。このプロジェクトは、先述ゲームの非公式英語翻訳プロジェクト「Rhythm Heaven Advance」およびその一部である「Rhythm Heaven Advance Plus」に追加される新機能を日本語版のリズム天国に移植したものとなります。
このプロジェクトは、現在**進行中**です！つまり、未完成もしくは不安定であるためパッチ等のダウンロードリンクは提供されていません。
ただし、プロジェクトのビルドの方法は以下に説明があります。プロジェクトがリリース可能な状態まで進んだ時点で、パッチのダウンロードが可能になる予定です。

ご質問、ご提案については[こちら](#連絡先)を参照下さい！

## インストール方法（ソースコードからビルドする）

### 必要条件

使用しているプラットフォームに限らず以下の物を用意する必要があります:
- 合法的に入手したリズム天国のROMデータ（前期、後期版どちらでも可） (CRC32: 前期 `349D7025` 後期 `A6CD88E1`)
- Git

### Windows

WSL(Windows Subsystem for Linux)を使用して、[Linux向けのインストール手順](#Linux)を踏んで下さい。 DebianもしくはUbuntuディストリビューションを推奨します。

*注：WSLを使用するにはBIOS設定で仮想化機能を有効にする必要があります。問題が発生した場合は、BIOS起動方法を確認し、お使いのコンピュータで仮想化機能を有効にしてください。その他のインストールに関する問題については、[Microsoft公式インストールガイド](https://docs.microsoft.com/ja-jp/windows/wsl/install)を参照してください。*

WSLのインストールに成功し、起動するとユーザー名、パスワードの入力、パスワードの確認が求められます。パスワードを入力する際、キーボード上で文字を入力してもアスタリスク等は表示されないため入力は慎重に行ってください。また、内容を忘れないようにしてください。

WSLをセットアップするには:
```bash
wsl --install
```

ユーザーを作成したら、ターミナルの設定を完了するために最後にいくつかコマンドを入力する必要があります。まず、`sudo apt update`と入力し実行、完了したら次に`sudo apt upgrade`と入力し実行します。これらのコマンドは途中でパスワードを求めてくるのでその都度パスワードを入力してください。もし`Do you want to continue? [Y/n]`と表示されたら`y`とだけ入力し、Enterキーを押してください。これで、WSLの設定は完了しました。

また、WindowsからLinuxのファイルにアクセスするためにドライブ文字を設定しておくと便利です。もし行う場合は、[このサイト（英語）](https://github.com/HackerN64/HackerSM64/wiki/Mounting-WSL-to-Drive)を参照してください。

このコマンドをコマンドプロンプトで入力した後、下記の手順に従ってコマンドを入力してください。

### Linux

#### 依存関係のインストール

ビルドに必要なパッケージをインストールします(Ubuntu/Debian):
```bash
sudo apt update
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev ffmpeg
```

#### devkitProのインストール

```bash
# ダウンロードおよびインストール (現在はShaffySwitcher氏のミラーを使用するようになっています)
wget https://www.shaffy.fr/install-devkitpro-pacman
chmod +x ./install-devkitpro-pacman
sudo ./install-devkitpro-pacman

# 環境変数の設定
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPPC=/opt/devkitpro/devkitPPC

# GBA開発ツールのインストール
sudo dkp-pacman -Sy
sudo dkp-pacman -S gba-dev
```

#### クローン及びビルド

1. **このリポジトリをクローンします:**
   ```bash
   git clone https://github.com/Toritan123/RhythmTengokuRePlus.git
   ```

2. **agbcc（ビルドに使用するツール）をクローンし、インストールします:**
   ```bash
   git clone https://github.com/pret/agbcc.git
   cd agbcc
   ./build.sh
   ./install.sh ../RhythmTengokuRePlus
   cd ../RhythmTengokuRePlus
   ```

3. **ROMファイルの配置:**
   - 先ほどの手順で作成されたRhythmTengokuRePlusフォルダにリズム天国のROMファイルをコピーします。
   - 名前を`baserom.gba`(もしくはMakefileで指定された名前)に変更します。

4. **ビルドを開始します:**
   ```bash
   make -j$(nproc)
   ```

リズム天国リプラスのROMデータが`build/`ディレクトリに生成されます。

### macOS

#### 依存関係のインストール

まずコマンドラインデベロッパツールをインストールします（ビルドに使用する`python3`などが含まれます）:
```bash
xcode-select --install
```

次に[Homebrew](https://brew.sh/ja/)をインストールします（既にインストール済みの場合はスキップ）:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

次に必要なパッケージをインストールします:
```bash
brew install git libpng ffmpeg
```

#### devkitProのインストール

[devkitProの公式サイト](https://devkitpro.org/wiki/Getting_Started)からmacOS向けの`.pkg`インストーラーをダウンロードし、インストールします。

インストール後、環境変数を設定します:
```bash
export DEVKITPRO=/opt/devkitpro
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPPC=/opt/devkitpro/devkitPPC
```

上記の`export`はそのターミナルを閉じると失われるため、次回以降も有効にするにはシェルの設定ファイルに追記します。macOSの標準シェル（zsh）の場合:
```bash
echo 'export DEVKITPRO=/opt/devkitpro' >> ~/.zshrc
echo 'export DEVKITARM=/opt/devkitpro/devkitARM' >> ~/.zshrc
echo 'export DEVKITPPC=/opt/devkitpro/devkitPPC' >> ~/.zshrc
```

シェルがbashの場合は`~/.zshrc`の代わりに`~/.bashrc`を使用してください。

次にGBA開発ツールをインストールします:
```bash
sudo dkp-pacman -Sy
sudo dkp-pacman -S gba-dev
```

#### クローン及びビルド

1. **このリポジトリをクローンします:**
```bash
   git clone https://github.com/Toritan123/RhythmTengokuRePlus.git
```

2. **agbcc（ビルドに使用するツール）をクローンし、インストールします:**
```bash
   git clone https://github.com/pret/agbcc.git
   cd agbcc
   ./build.sh
   ./install.sh ../RhythmTengokuRePlus
   cd ../RhythmTengokuRePlus
```

3. **ROMファイルの配置:**
   - RhythmTengokuRePlusフォルダにリズム天国のROMファイルをコピーします。
   - 名前を`baserom.gba`に変更します。

4. **ビルドを開始します:**
```bash
   make -j$(sysctl -n hw.logicalcpu)
```

リズム天国リプラスのROMデータが`build/`ディレクトリに生成されます。
## インストール後のカスタマイズ
リズム天国プラスでは「PLAYTEST」と「DEBUG」の二つの機能をカスタマイズすることができます。

- **PLAYTEST:** メダル99枚　全ゲームを解放する
- **DEBUG:** メインメニューで「リズムゲーム」選択時にL+R同時押しでデバッグメニュー　ゲーム中にL+Rでオートプレイ

ビルドを開始する際に
（初めてROMをビルドする場合は1行目を省くことができます）
```bash
make distclean
make -j$(nproc) FEATURES="PLAYTEST DEBUG"
```
のように実行すると指定した機能を入れてROMを再ビルドできます。
また、入れたい機能が1つだけの場合
`make -j$(nproc) FEATURES=PLAYTEST`
のように`""`を省略できます。

## クレジット
リズム天国リプラスのクレジットは[こちら](CREDITS_rtrp.md)

本家プロジェクト・Rhythm Heaven Advanceのクレジットは[こちら](CREDITS_rha.md)

## 連絡先

- [リズム天国リプラス　email](rhythmtngkreplus@icloud.com)

- [Rhythm Heaven Advanceのdiscordサーバー](https://discord.gg/8PET8w8PU8)
**（質問などRhythm Heaven Advanceより移植されたものについてはこちらで発言しても構いませんが、リズム天国プラス、リズム天国リプラス独自の内容に関する質問はこのdiscordサーバーではお控えください！）**

- **GitHub(Issues):** [バグを報告](https://github.com/Toritan123/RhythmTengokuRePlus/issues)
その他のご質問や不明点がございましたら、[rhmodding discord server（英語）](https://discord.com/invite/ps4rq53)へどうぞ！（リズム天国の改造関連についてのサーバーです）

## 注意事項

これは非公式のファンプロジェクトであり、任天堂と提携・承認・関連するものではありません。全ての商標権及び著作権はそれぞれの所有者に帰属します。本パッチは合法的に入手したゲームソフトでの個人利用のみを目的としています。

本パッチを商業目的で使用することは一切禁止されています。

リズム天国に関するアセット及びソースコードの全ての権利は、オリジナル作者及び任天堂が保有します。


This is an unofficial fan project and is not affiliated with, endorsed by, or associated with Nintendo. All trademarks and copyrights belong to their respective owners. This patch is intended for personal use only with legally obtained copies of the game.

You are NOT permitted to use the patch for commercial purposes.

All rights concerning the assets or source code are reserved by the original authors and Nintendo for Rhythm Tengoku.
