from conans import ConanFile

class ConfigConan(ConanFile):
    name = "csb64"
    version = "0.0.1"
    license = "MIT"
    description = """Command line interface for SimpleBase64 encoder and decoder."""
    settings = "os", "compiler", "build_type", "arch"
    tool_requires = "boost/1.81.0"
    generators = "cmake_find_package"
