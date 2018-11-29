**This document will be submitted as a Temporary Document to ITU-T Study Group 12 meeting, Geneva, 27 November - 6 December 2018​**

# Status report on the open-source Software Tool Library activity

## Summary

This report provides a progress report on the operation of the ITU-T Software Tool Library (STL) as an open-source initiative, as a mechanism to include a wider base of users and coders to maintain and enlarge the ITU-T STL.
The activity was launched by SG12 in 2017 and is currently fully operational within GitHub [https://github.com/openitu/STL].

The first version of the Recommendation was approved in March 1993 and proposed a set of tools to facilitate speech processing in standardization activities. 
G.191 contains a summary of all the tools implemented in the STL, and the library itself as an electronic attachment.
The Recommendation was subsequently updated over the years by enthusiast ITU-T members, in a collaborative effort frequently involving external players and using an open-source license.
Opening the development of the STL, and this Recommendation, to the to open-source community was the next natural step.

A substantial amount of work was necessary to port the existing code to the GitHub open-source platform.
This included: 

- the generation of configuration files for cross-platform build toolchains and regression tests [CMake](https://cmake.org/), 
- the integration of the project with Continuous Integration platforms [Travis CI](https://travis-ci.org), 
- the conversion of documents into plain text format [MarkDown](https://daringfireball.net/projects/markdown),
- bug fixing to account for restrictive compilers,
- the harmonization of source code style

The STL was further extended with the new basic operators contributed by 3GPP SA4 [#26.973 v15.1.0](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=3326).
These extension offers support for complex, 64-bit and enhanced 32-bit operators.

The open-source community is pleased to submit the first release of Software Tool Library to the ITU for standardization. 
The revised draft Recommendation is available as [SG12-TD648](https://www.itu.int/md/T17-SG12-181127-TD-GEN-0648/en).

# Proposed next steps

## Liaison statement to 3GPP SA4 and other relevant SDOs

It is propose to send a liaison statement to 3GPP SA4 for the following reasons:

- To provide a status of STL2018
- To ask feedback on which compilers and operating systems should be supported 
- To encourage contributions directly to GitHub to reduce the communication time overhead introduced by the exchange of Liaison Statements
- [3GPP SA4 only] To appoint one or more 3GPP SA4 delegates for discussion and code review on GitHub

## Review and integrate relevant STL2014 code

Several code changes were identified by Study Group 16 for a 2014 release of the STL 2014, but Recommendation G.191 has not been updated since 2010 due to changes in Rapporteurship.
Some of the updates proposed in STL2014 relate to the basic operators.
The code should be reviewed the make sure the updates do not interfere with the new basic operators from 2018.
If there are conflicts, they need to be investigated with relevant parties and 3GPP SA4 in particular.

## Update the STL manual

An updated version of the STL Users Manual is being drafted and is available on the GitHub platform (https://github.com/openitu/STL/tree/dev/manual).
- The text of the manual should be reviewed for correctness
- Text for the new basic operators needs to be incorporated 
- The current text related to the STL2014 additions should be reviewed

## Clean up of documentation

It is proposed to unify the source code documentation and README files.

## Review the supported infrastructure (compilers and operating system)

It is desirable to limit the number of supported platforms to ease maintenance.
Some of the supported compilers are no longer available, making regression tests difficult to verify.

Maintaining the compatibility with very old compilers may also limit the level of code clean up that can be realized.

## Addition test cases

Additional test cases should be created to ensure that all compiled binaries are operating as expected.

## Creation of programming language bindings

Creating language binding (e.g. Python) for the most popular functions might increase the use of the STL library.

## Release cycle and roadmap

Open-source code is a continuous effort and constantly evolves.
To keep up the momentum, it is suggested to set milestones revised at each SG12 meeting.

ITU-T SG12 Recommendations are typically updated at rate of 2 years or more, although revisions of the STL may be proposed for consent at a faster pace if substantial improvements are available.

# Lessons learnt

Developing code in an open source environment is very different from developing code in a closed environment.

## Review process

GitHub review process ensures that each submission, known as *Pull Requests* (PRs), is reviewed by another peer.
This step can be a slow process depending of the availability of reviewers, the number of lines submitted and the amount of interactions between the submitter and the reviewers.

However the review process comes with great advantages. 
As all changes are scrutinized and discussed, the review process leads to higher quality code.

To facilitate the review, PRs should be accompanied with appropriate explanation.
They should be kept small, with changes (new or modified lines) limited to the purpose of the PRs.
It is desirable to break down PRs into smaller ones when too many changes occur.
This not only has the advantage to reduce the time needed for code review, but also to create more intelligible logs.

## Deadlines help keep the momentum

## Getting proficient at Git

GitHub provides an effective set of tools for code review and enables focused discussions on specific parts of the code. 
However, there is an initial learning curve to make good use of the different possibilities.
Some examples follow.

While GitHub provides great tools for reviewing PRs, it does not provide much help for editing files beyond simple code change commits.
It is likely that when PRs are submitted, changes may be requested by the reviewers, which may require advanced Git operations such as cherry-picking or rebasing.

Preparing several pull requests at the same time may require juggling between branches. 
It is sometime easier to create different clones of the repository.

These operations require a good understanding of Git and GitHub.
The following pages could be a good start:
- [https://git-scm.com/docs/gittutorial]
- [https://help.github.com/categories/collaborating-with-issues-and-pull-requests]

## Continuous integration

Setting up continuous integration on the open-source repository helps verify that new PRs do not break the code.
Continuous integration, such as [Travis CI](https://travis-ci.org), fetches and compiles the code for each PR, then performs specified regression tests.
These can be set up for different operating systems and compilers.

The code used for regression tests may need to be adapted in order to return information easily consumable by the test framework.


# For discussion: more ITU-T Recommendations on GitHub?

Should we consider incorporating more ITU-T Recommendations to the openitu GitHub repository?

Implementations of the E.Model (Rec. ITU-T G.107) could be intergrated within the STL.

Other examples are Recommendations ITU-T P.563 and P.862 which come with source code that could be easily ported to GitHub (subject to permission of copyright owners).
