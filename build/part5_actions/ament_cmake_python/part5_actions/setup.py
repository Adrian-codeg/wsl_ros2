from setuptools import find_packages
from setuptools import setup

setup(
    name='part5_actions',
    version='0.0.0',
    packages=find_packages(
        include=('part5_actions', 'part5_actions.*')),
)
