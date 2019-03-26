#!/bin/sh

#  api-reference.sh created on 2019-03-20.
#  Generates 'doc/api-refence.html' from all .h headers in 'lib/' folder.


#  Set output path. Default path: 'doc/.HeaderDoc/'
HTML_OUTPUT_PATH=doc/.HeaderDoc/

#  Run 'headerdoc2html' to generate .html reference pages
bin/headerdoc2html -o ${HTML_OUTPUT_PATH} $(find -E lib -regex '.*\.h')

#  Create main Table of Contents from the generated .html files
bin/gatherheaderdoc ./doc api-reference.html

#  Keep all Headerdoc folders
find ${HTML_OUTPUT_PATH} -type d -exec touch {}/.keep \;
