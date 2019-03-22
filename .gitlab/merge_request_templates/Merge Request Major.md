<!--  Merge Request Major template markdown document  -->



## Description
<!-- Describe what you are adding / removing -->

_{-No description.-}_




## Related issues
<!-- Link related issues below. -->
<!-- Insert the issue link or reference after the word "Closes" if merging this should automatically close it. -->

_{-No related issues.-}_





## Author's checklist
<!--  Review changes before requesting merge  -->

- [ ] Follow GitLab [User Documentation][user] and [Style Guide][styleguide].
- [ ] Open a [new issue][issues/new] or select an [opened issue][issues].
- [ ] Apply relevant [project labels][labels]. 
- [ ] Assign [someone][team] to review your request.
- [x] Notify other members about changes.
- [ ] Document code using [HeaderDoc][hdoc] syntax:        

        /*!
        *  @class Server
        *
        *  @brief A single threaded network server for transferring text.
        *
        *  The Server class transfers text to and from multiple Client 
        *  instances connected on a given port. The behavior is ...
        */
        class Server { ... }





## Reviewers' checklist
<!--  Review and accept merge request  -->

- [ ] Commit successfully passes all  __build__, __analyze__, and __test__ stages.
- [ ] Review new references in master [API Reference Table of Contents][hdoc-toc], if any were added.
- [ ] Team review
- [ ] Review by assigned maintainer to confirm __accuracy__, __clarity__, and __completeness__.
    * This can be skipped for requests without substantive content changes.







## Notification
<!--  Major changes notify all team members  -->  

/cc @ica29 @jjankows @jha257 @mpuchkov @parmj @tnpham @vun











### Further details

<!-- Follow the documentation workflow https://docs.gitlab.com/ee/development/documentation/workflow.html -->
<!-- Additional information is located at https://docs.gitlab.com/ee/development/documentation/ --> 
<!-- For changing documentation location use the "Change documentation location" template -->


---

_Major update_

/label ~important ~major




<!--  Links  -->
[guidelines]: https://docs.gitlab.com/ee/development/documentation/
[styleguide]: https://docs.gitlab.com/ee/development/documentation/styleguide.html
[user]: https://csil-git1.cs.surrey.sfu.ca/help/user/index.md
[labels]: /../labels/
[issues]: /../issues/
[issues/new]: /../issues/new/
[team]: /../project_members/
[hdoc]: /../wikis/HeaderDoc/
[hdoc-toc]: /../doc/api-reference.html
