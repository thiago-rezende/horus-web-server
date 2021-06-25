<!-- Horus Web Server -->

<!-- Logo -->
<img src=".github/logo.png" align="right" width="129"/>

<!-- Title -->
# Horus Web Server
[![ci-badge]][ci-url] [![license-badge]][license-url] [![cpp-badge]][cpp-url] [![meson-badge]][meson-url]
<!-- Short Description -->
> Simple and (not yet) configurable web server written in [C++][cpp-url]

<!-- Description -->
This project was developed as a practical application of the subject of computer networks from the information systems course.

<!-- Disclaimer -->
> :warning: **DO NOT USE IN PRODUCTION!**

---

<!-- Usage -->
## Usage
```sh
  horus-web-server [OPTION...]

      --port arg  port number
      --doc arg   document root
  -h, --help      print help
```

<!-- Requirements -->
## Requirements
 - [LLVM/clang][clang-url] or [MSVC/Visual Studio][visual-studio-url]
 - [Python][python-url]
 - [Meson Build System][meson-url]
 - [Ninja Build][ninja-url]
 - [Git][git-url]

<!-- Build Instructions -->
## Build Instructions
> Clone the repo
```sh
git clone https://github.com/thiago-rezende/horus-web-server.git
```
> Configure builddir
```sh
cd horus-web-server
meson --buildtype=release --prefix="$HOME/horus-ws" builddir
```
> Build
```sh
ninja -C builddir install
```
> Run
```sh
$HOME/horus-ws/bin/horus-web-server --help
```

<!-- Links -->
[ci-url]: https://github.com/thiago-rezende/horus-web-server/actions
[license-url]: https://opensource.org/licenses/BSD-3-Clause
[cpp-url]: https://en.cppreference.com/w/cpp
[meson-url]: https://mesonbuild.com/
[ninja-url]: https://ninja-build.org/
[clang-url]: https://clang.llvm.org/
[visual-studio-url]: https://visualstudio.microsoft.com/
[python-url]: https://www.python.org/
[git-url]: https://git-scm.com/

<!-- Badges -->
[license-badge]: https://img.shields.io/badge/license-BSD--3--Clause-informational?style=flat-square
[meson-badge]: https://img.shields.io/badge/Meson-0.54.0-blueviolet.svg?style=flat-square
[cpp-badge]: https://img.shields.io/badge/C++-17-orange.svg?style=flat-square
[ci-badge]: https://img.shields.io/github/workflow/status/thiago-rezende/horus-web-server/ci?label=CI&style=flat-square
