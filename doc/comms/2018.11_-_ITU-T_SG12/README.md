**This document will be submitted as a Temporary Document to ITU-T Study Group 12 meeting, Geneva, 27 November - 6 December 2018​**

# Status report on the open-source Software Tool Library activity

## Summary

This report provides a progress report on the operation of the ITU-T Software Tool LIbrary (STL) as an open-source initiative, as a mechanism to include a wider base of users and coders to maintain and enlarge the ITU-T STL.
The activity was launched by SG12 in 2017 and is currently fully operational within GitHub (*ADD URL TO REPOSITORY*).

The first Recommendation offered within this framework is ITU-T Rec. G.191, the Software Tool Library (STL).
[TODO] The first version of the Recommendation was approved in March 1993 and proposed a set of tools to facilitate speech processing in standardization activities. G.191 contains a summary of all the tools implemented in the STL, and the library itself as an electronic attachment.
The Recommendation was subsequently updated over the years by enthusiast ITU-T members, in a collaborative effort frequently involving external players and using an open-source license.
Opening the development of the STL - and this Recommendation - to the to open-source community was the next natural step.

A substantial amount of work was necessary to port the existing code to the GitHub open-source platform.
This included: 

- the generation of configuration files for cross-platform build toolchains and regression tests (CMake), 
- the integration of the project with Continuous Integration platforms (Travis), 
- the conversion of documents into plain text format (MarkDown),
- bug fixing to account for restrictive compilers,
- the harmonization of source code style

The STL was further extended with the new basic operators contributed by 3GPP SA4 [#26.973 v15.1.0](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=3326).
These extension offers support for complex, 64-bit and enhanced 32-bit operators.

The open-source community is pleased to submit the first release of Software Tool Library to the ITU for standardization.
The revised draft Recommendation is available as [SG12-TD648](https://www.itu.int/md/T17-SG12-181127-TD-GEN-0648/en).

# Proposed next steps

## Liaison statement to 3GPP SA4

It is propose to send a liaison statement to 3GPP SA4 for the following reasons:

- To provide them with a status of STL2018

- To ask 3GPP SA4 experts whether / which of the previously defined basic operators are still in use *DO WE WANT TO ASK THIS QUESTION? EARLIER VERSIONS OF RECOMMENDATIONS MAY STILL USE THEM AND 3GPP WILL NOT KNOW IT.*

- To ask their feedback on which compilers and operating system should be supported *WHY ONLY 3GPP?*

- To discuss more efficient communication channels than Liaison Statements between 3GPP SA4 and ITU concerning updated of the STL.*NEED TO BE SPECIFIC.*
For example, have one or more 3GPP SA4 delegates actively participating on GitHub for discussions and code reviews relevant to 3GPP? 

## Review and integrate relevant STL2014 code

Several code changes were identified by Study Group 16 for a 2014 release of the STL 2014, but Recommendation G.191 has not been updated since 2010 due to changes in Rapporteurship.
Some of the updates proposed in STL2014 relate to the basic operators.
The code should be reviewed the make sure the updates do not interfere with the new basic operators from 2018.
If there are conflicts, they need to be investigated with relevant parties and 3GPP SA4 in particular.

## Update the STL manual
An updated version of the STL Users Manual is being drafted and is available in the GitHub platform (*ADD URL*). 
* The text of the manual should be reviewed for correctness.

* Text for the new basic operators needs to be incorporated. 

* The current text related to the STL2014 additons should be reviewed.

## Clean up of documentation

It is proposed to unify the source code documentation and README files.

## Review the supported infrastructure (compilers and operating system)

It is desirable to limit the number of supported platforms to ease maintenance and technical debt (*?DEBT?*). Some of the supported compilers are no longer available, making regression tests difficult to verify.

Maintaining the compatibility with very old compilers may also limit the level of code clean up that can be realized.

## Incorporating more ITU-T Recommendations?
*FOR ME THIS IS MIXING UP TWO SEPARATE ISSUES - G.191 as an open source software, which I think is the objective of this document, and then what other Recs could be included in the GitHub - but then as open source? (With all the IPR implications that it carries...). Maybe better addressed in separate documents? Or you propose to add the Recs below as part of the STL itself (not the openITU platform)*

Should we consider incorporating more ITU-T Recommendations to the openitu GitHub repository?

For example Recommendations ITU-T P.563, P.861, P.862 come with source code that could be easily ported to GitHub, subject to permission to publish code.

There might be also interest in implementing the E.Model (Rec. ITU-T G.107).

## Addition test cases

Additional test cases should be created to ensure that all compiled binaries are operating as expected.

## Creation of programming language bindings

Creating language binding (e.g. Python) for the most popular functions might increase the use of the STL library.

## Release cycle and roadmap

Open-source code is a continuous effort and constantly evolves.
To keep up the momentum, it is suggested to set milestones for each SG12 meeting. *OR: To set milestones revised at each SG12 meeting.*

ITU-T SG12 Recommendations are typically updated at rate of 2 years or more, although revisions of the STL may be proposed for consent at a faster pace if substantial improvements are available.


# Lessons learnt

Developing code in an open source environment is very different from developing code in a closed environment.

## Review process

*changed the order of a few sentences*

GitHub review process ensures that each submission, known as *Pull Requests* (PRs), is reviewed by another peer.
This step can be a slow process depending of the availability of reviewers, the number of lines submitted and the amount of interactions between the submitter and the reviewers.

However the review process comes with great advantages. 
As all changes are scrutinized and discussed, the review process leads to higher quality code.

To facilitate the review, PRs should be accompanied with appropriate explanation.
They should be kept small, with changes (new or modified lines) limited to the purpose of the PRs.
It is desirable to break down PRs into smaller ones when too many changes occur.
This not only has the advantage to reduce the time needed for code review, but also to create more intelligible logs.

## Deadlines help keep the momentum

## Getting proficient at GIT

GitHub provides an effective set of tools for code review and enables focused discussions on specific parts of the code. However, there is a substantial initial learning curve to make good use of the different possibilities. Some examples follow.

While GitHub provides great tools for reviewing PRs, it does not provide much help for editing files beyond simple code change commits.
It is likely that when PRs are submitted, changes may be requested by the reviewer, which may require advanced GIT operations such as cherry-picking or rebasing.
These operations require a good understanding of the GIT platform (*GIT or GIThub?*).

Furthermore, GitHub process for preparing PRs are typically to: clone the repository to your account, perform the edits, then push the changes to the source repository.
GitHub does not allow cloning the same project more than once for any given account, which is inconvenient when working on several PRs.
It may be necessary to use different accounts or to maintain the synchronization between your local repository and there original repository before starting the edits.

## Continuous integration

Setting up continuous integration on the open-source repository helps verify that new PRs do not break the code.
Continuous integration, such as Travis (*add reference/URL*), fetches and compiles the code for each PR, then performs specified regression tests.
These can be set up for different operating systems and compilers.

The code used for regression tests may need to be adapted in order to return information easily consumable by the test framework.

*Should we add an annex with GitHub concepts? Eg pull request, commit, cherry-picking, rebasing, cloning, fork, ...)
