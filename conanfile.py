from conans import ConanFile

class ConfigConan(ConanFile):
    name = "cli-sb64"
    version = "1.0"
    author = "Stephen Aaron Hannon <hannonstephen19@gmail.com>"
    license = "MIT"
    description = """Command line interface for sb64 base 64 encoder/decoder."""

    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    requires = "sb64/1.0@flamedesktoplocal/stable"
    tool_requires = "boost/1.81.0"
    upload_policy = "skip"

    exports_sources = "CMakeLists.txt", "CMakePresets.json", "LICENSE.txt", "target/*", "util/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()
