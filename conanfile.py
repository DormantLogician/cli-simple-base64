from conans import ConanFile

class ConfigConan(ConanFile):
    name = "cli-sb64"
    version = "v1"
    license = "MIT"
    description = """Command line interface for sb64 base 64 encoder/decoder."""
    settings = "os", "compiler", "build_type", "arch"
    tool_requires = "boost/1.81.0"
    generators = "cmake_find_package"
