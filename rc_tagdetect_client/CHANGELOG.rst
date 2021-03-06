^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rc_tagdetect_client
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

3.0.4 (2020-09-23)
------------------

3.0.3 (2020-09-22)
------------------

3.0.2 (2020-07-28)
------------------

3.0.1 (2020-05-14)
------------------

3.0.0 (2020-05-13)
------------------
* refactoring and cleanup
* return success on StartContinuousDetection for consistency with stop
* set parameters on parameter server so that dynamic reconfigure picks them up
* enum for dynamic reconfigure quality params
* add optional pose_frame in request
* update cpr for support of curl >= 7.62.0
  and set EXCLUDE_FROM_ALL to not install it
* update nlohmann json to 3.7.3
* Contributors: Felix Ruess

2.7.0 (2019-07-19)
------------------
* add `device` parameter that can take serial number or GEV name
  (has precedence over old `host` parameter)

2.6.4 (2019-06-19)
------------------

2.6.3 (2019-06-12)
------------------

2.6.2 (2019-06-11)
------------------

2.6.1 (2019-05-20)
------------------

2.6.0 (2019-05-20)
------------------
* first release
