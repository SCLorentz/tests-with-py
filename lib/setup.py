from setuptools import setup, Extension

mod = Extension(
    "my_asm",
    sources=["python.c"]
)

setup(
    name="my_asm",
    version="0.1",
    description="Um modulo que reviza as funções de python para assembly",
    author="SCLorentz",
    ext_modules=[mod]
)