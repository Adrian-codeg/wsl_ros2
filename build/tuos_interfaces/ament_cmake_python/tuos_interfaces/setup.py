from setuptools import find_packages
from setuptools import setup

setup(
    name='tuos_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('tuos_interfaces', 'tuos_interfaces.*')),
)
