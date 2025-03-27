from setuptools import find_packages
from setuptools import setup

setup(
    name='part4_services_modules',
    version='0.0.0',
    packages=find_packages(
        include=('part4_services_modules', 'part4_services_modules.*')),
)
