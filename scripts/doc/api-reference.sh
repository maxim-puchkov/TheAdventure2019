#!/bin/sh

#  api-reference.sh created on 2019-03-20.
#  Generates 'doc/api-refence.html' from all .h headers in 'lib/' folder.


#  Generate HTML files
HTML_OUTPUT_PATH=doc/.HeaderDoc/
bin/headerdoc2html -o ${HTML_OUTPUT_PATH} $(find -E lib -regex '.*\.h')

#  Generate main Table of Contents
bin/gatherheaderdoc ./doc api-reference.html
