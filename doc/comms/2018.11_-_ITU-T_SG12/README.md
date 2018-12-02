**This document will be submitted as a Temporary Document to ITU-T Study Group 12 meeting, Geneva, 27 November - 6 December 2018​**

# Status report on the open-source Software Tool Library initiative

## Summary

This report provides an update on the development of the ITU-T Study Group 12 open-source initiative.
The project was initiated in 2017 with the goal of offering the open-source community a way to contribute to ITU-T standardization activities.

The first Recommendation offered within this framework is ITU-T Rec. G.191, the Software Tool Library (STL).
[TODO] The first version of the Recommendation was approved in XXX and proposed a set of tools to facilitate speech processing in standardization activities.
The Recommendation was subsequently updated over the years by enthusiast ITU-T members, in an open-source spirit.
Proposing this Recommendation to the open-source community was the next natural step.

A substantial amount of work was necessary to port the existing code to an open-source platform.
This included: 

- the generation of configuration files for cross-platform build toolchains and regression tests (CMake), 
- the integration of the project with Continuous Integration platforms (Travis), 
- the conversion of documents into plain text format (MarkDown),
- bug fixing to account for restrictive compilers,
- the harmonization of source code style

The STL was further extended with the new basic operators contributed by 3GPP [#26.973 v15.1.0](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=3326).
These extension offers support for complex, 64-bit and enhanced 32-bit operators.

The open-source community is pleased to submit the first release of Software Tool Library to the ITU for standardization.
The revised draft Recommendation is available as [TD0648](https://www.itu.int/md/T17-SG12-181127-TD-GEN-0648/en).

# Proposed next steps

## Liaison statement to 3GPP

It is proposed to send a liaison statement to 3GPP for the following reasons:

* To provide them with a status of STL2018

* To ask 3GPP experts whether any of the old basic operators are still in use

* To ask their opinion on which compilers and operation system should be supported

* To discuss more efficient communication channels than Liaison Statements between 3GPP and ITU.
Maybe one 3GPP delegate could actively participate on GitHub for discussions and code reviews relevant to 3GPP? 

## Review and integrate relevant STL2014 code

Some code changes were proposed in Study Group 16 for a release of STL 2014, but Recommendation G.191 has never been updated.
Some of the updates proposed in STL2014 relate to the basic operators.
The code should be reviewed the make sure the updates do not interfere with the new basic operators from 2018.
If there are conflicts, we should discuss with 3GPP.

## Update the STL manual

* The text of the manual should be reviewed for correctness.

* Text for the new basic operators should be incorporated. 

* The current text related to the STL2014 should be reviewed.

## Clean up of documentation

It is proposed to unify the source code documentation and README files.

## Review the supported infrastructure (compilers and operating system)

It is desirable to limit the number of supported platform in order to ease maintenance and technical debt. Some of the supported compilers are no longer available, making regression tests difficult to verify.

Maintaining the compatibility with very old compilers may also limit the level of code clean up that could be realized.

## Incorporating more ITU-T Recommendations?

Should we consider incorporating more ITU-T Recommendations to the openitu GitHub repository?

For example Recommendations P.563, P.861, P.862 come with source code that could be easily ported to GitHub, subject to permission to publish code.

There might be also interest in implementing the E.Model (ITU-T Rec. G.107).

## Addition test cases

Additional test cases should be created to ensure that all compiled binaries are operating as expected.

## Creation of language bindings

Creating language binding (e.g. Python) for the most popular functions might increase the use of the STL library.

## Release cycle and roadmap

Open-source code is a continuous effort and constantly evolves.
To keep the momentum, it is suggested to set milestones for each SG12 meeting.

ITU-T SG12 Recommendations are typically updated at rate of 2 years or more, although revisions of the STL may be proposed for consent at a faster pace if substantial improvements are available.


# Lessons learnt

Developing code in an open source environment is very different from developing code in a closed environment.

## Review process

GitHub review process ensures that each submission, known as Pull Requests (PR), is reviewed by another peer.
This step can be a slow process depending of the availability of reviewers, the number of lines submitted and the amount of interactions between the submitter and the reviewers.

However the review process comes with great advantages. 
To facilitate the review, PRs should be accompanied with appropriate explanation.
They should be kept small, with changes (new or modified lines) limited to the purpose of the PRs.
It is desirable to break down PRs into smaller ones when too many changes occur.
This not only has the advantage to reduce the speed of the code review but also to create more intelligible logs.

As all changes are scrutinized and discussed, the review process leads to higher quality code.

GitHub provides a effective tools for code review and enables focused discussions on specific parts of the code.

## Deadlines helped keep the momentum

## Getting proficient at GIT

While GitHub provides great tools for reviewing PRs, it does not provide much help for editing files beyond simple commits.
It is likely that when PRs are submitted, changes may be requested by the reviewer, which may required advanced GIT operations such as cherry-picking or rebasing.
These operations require a good understanding of GIT.

Furthermore GitHub process for preparing PRs are typically to: clone the repository to your account, perform the edits, then push the changes to the source repository.
GitHub does not allow cloning the same project more than once for any given account which is inconvenient when working on several PRs.
It may be necessary to use different accounts or to maintain the synchronization between your local repository and there original repository before starting the edits.

## Continuous Integration

Setting up continuous integration on open-source repository helps verify that new PRs do not break the code.
Continuous integration, such as Travis, fetches and compiles the code for each PR, then performs specified regression tests.
These can be set up for different operating systems and compilers.

The code used for regression tests may need to be adapted in order to return information easily consumable by the test framework.
