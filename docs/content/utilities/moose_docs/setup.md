# MooseDocs Setup

MOOSE contains a single-source documentation system for creating websites, slideshows, and pdfs
using [markdown](https://en.wikipedia.org/wiki/Markdown) syntax, including a custom syntax aimed to simply the
process: [Moose Flavored Markdown](moose_markdown/index.md).

## Dependencies
If you are using a current [MOOSE package](getting_started/installation/index.md) then a majority of the setup is complete, you will
only need to load the git-lfs module (See "Install Git LFS in Manual Setup below for more detail).

If you are working on documentation in MOOSE or an application that has existing documentation then
you will need to run the following command from within the repository to download any existing
images.

```bash
git lfs pull
```

## Configuration
If you are adding documentation to an existing project then you will need to add a few files to
configure the documentation system to work properly for your application.


###### (1) Create "docs" Location
Create a "docs" directory, this is a directory where you will utilize to store your
documentation related files.

!!!info
    Most existing applications will have a "doc" directory, this can be used if desired or another
    location can be created. The location and name of this directory is arbitrary.

###### (2) Add MooseDocs Executable
To use MooseDocs an executable is required, this main executable is simply copied from the
executable within [MOOSE]:

```bash
cp ~/projects/moose/docs/moosedocs.py ~/projects/your_application_name/docs
```

This executable contains command-line base help, which can be accessed using the "-h" flag as
follows.

```
cd ~/projects/your_application_name/docs
./moosedocs.py -h
```

At this point you are ready to begin creating a configuration file for one of the various forms
of documentation that MooseDocs is capable of producing:

* [Creating a Web-Site](moose_docs/website.md)
* [Building a Presentation](moose_docs/presentation.md)
* [Generating a PDF](moose_docs/pdf.md)


## Manual Setup
If you are not using a MOOSE package, then the following steps may be performed to install the
necessary dependencies for using the documentation system.

(1) Install Git LFS
Install the latest Git Large File Storage package for your system. If you are using the MOOSE redistributable, you should already
have git-lfs on your system. You simply need to load the following module (put it in your .bash_profile or .bashrc_local file):
```bash
module load git-lfs
```
Otherwise, follow the getting started instruction from [git-lfs.github.com](https://git-lfs.github.com/). If you are working on
documentation in MOOSE or an application that has existing documentation then
you will need to run the following command from within the repository to download any existing images.

```bash
git lfs pull
```

(2) Create a new python environment.

This will create a special python environment suitable for using the documentation system, this is done so that an existing
python configuration you have will not be damaged.

```bash
conda create --name docs --clone root
```

(3) Activate the new environment.

This command will need to be executed within any terminal that you plan to perform documentation related tasks.

```bash
source activate docs
```

(4) Install the additional python packages.

```bash
pip install python-markdown-math bs4 pybtex jinja2 livereload lxml pylatexenc anytree pandas
```
