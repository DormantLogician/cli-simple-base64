import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, CMakeDeps

class ConfigConan(ConanFile):
    name = "csb64"
    version = "1.0"
    author = "Stephen Aaron Hannon <hannonstephen19@gmail.com>"
    license = "MIT"
    description = """Command line interface for sb64 base 64 encoder/decoder."""
    upload_policy = "skip"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": False}

    exports_sources = "CMakeLists.txt", "CMakePresets.json", "LICENSE.txt", ".clang-tidy", "target/*", "util/*"

    def requirements(self):
        self.run("cmake -P util/task/setup_deps.cmake", cwd=self.source_folder)
        self.requires("boost/1.86.0")
        self.requires("sb64/1.0")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def generate(self):
        tc = CMakeToolchain(self)

        if self.settings.get_safe("compiler") == "clang":
            tc.variables["CMAKE_CXX_FLAGS"] = "-fno-strict-overflow -fno-strict-aliasing -fno-delete-null-pointer-checks -Wuninitialized -Winit-self -D_FORTIFY_SOURCE=3 -D_GLIBCXX_ASSERTIONS -ftrivial-auto-var-init=zero -fPIE -fstack-protector-strong"
            tc.variables["CMAKE_CXX_FLAGS_DEBUG"] = "-g -O0"
            tc.variables["CMAKE_CXX_FLAGS_RELEASE"] = "-O2"
            tc.variables["CMAKE_CXX_FLAGS_RELWITHDEBINFO"] = "-g -O2"
            tc.variables["CMAKE_CXX_FLAGS_MINSIZEREL"] = "-Os"
            tc.variables["CMAKE_CXX_FLAGS_TEST"] = "-fsanitize=undefined,address,leak -fno-omit-frame-pointer"
            tc.variables["CMAKE_CXX_FLAGS_PROFILE"] = "-O0 -pg"
            tc.variables["CMAKE_CXX_FLAGS_COVERAGE"] = "--coverage -O0"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_TEST"] = "-fsanitize=undefined,address,leak -fno-omit-frame-pointer"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_PROFILE"] = "-O0 -pg"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_COVERAGE"] = "--coverage -O0"

        if self.settings.get_safe("compiler") == "gcc":
            tc.variables["CMAKE_CXX_FLAGS"] = "-fno-strict-overflow -fno-strict-aliasing -fno-delete-null-pointer-checks -Wuninitialized -Winit-self -D_FORTIFY_SOURCE=3 -D_GLIBCXX_ASSERTIONS -ftrivial-auto-var-init=zero -fPIE -fstack-protector-strong"
            tc.variables["CMAKE_CXX_FLAGS_DEBUG"] = "-g -O0"
            tc.variables["CMAKE_CXX_FLAGS_RELEASE"] = "-O2"
            tc.variables["CMAKE_CXX_FLAGS_RELWITHDEBINFO"] = "-g -O2"
            tc.variables["CMAKE_CXX_FLAGS_MINSIZEREL"] = "-Os"
            tc.variables["CMAKE_CXX_FLAGS_TEST"] = "-fsanitize=undefined,address,leak -fno-omit-frame-pointer"
            tc.variables["CMAKE_CXX_FLAGS_PROFILE"] = "-O0 -pg"
            tc.variables["CMAKE_CXX_FLAGS_COVERAGE"] = "--coverage -O0"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_TEST"] = "-fsanitize=undefined,address,leak -fno-omit-frame-pointer"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_PROFILE"] = "-O0 -pg"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_COVERAGE"] = "--coverage -O0"

        if self.settings.get_safe("compiler") == "msvc":
            tc.variables["CMAKE_CXX_FLAGS"] = "/guard:cf /GS /EHsc"
            tc.variables["CMAKE_CXX_FLAGS_DEBUG"] = "/DEBUG"
            tc.variables["CMAKE_CXX_FLAGS_RELEASE"] = "/O2"
            tc.variables["CMAKE_CXX_FLAGS_RELWITHDEBINFO"] = "/DEBUG /O2"
            tc.variables["CMAKE_CXX_FLAGS_MINSIZEREL"] = "/Os"
            tc.variables["CMAKE_CXX_FLAGS_TEST"] = "/DEBUG /fsanitize=address /Oy"
            tc.variables["CMAKE_CXX_FLAGS_PROFILE"] = "/GENPROFILE"
            tc.variables["CMAKE_CXX_FLAGS_COVERAGE"] = "/O0"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_TEST"] = "/DEBUG /fsanitize=address /Oy"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_PROFILE"] = "/GENPROFILE"
            tc.variables["CMAKE_EXE_LINKER_FLAGS_COVERAGE"] = "/O0"

        tc.generate()

        cmake = CMakeDeps(self)
        cmake.generate()

    def layout(self):
        self.folders.source = "."
        self.folders.build = "built"
        self.folders.generators = os.path.join(self.folders.build, "generators")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
