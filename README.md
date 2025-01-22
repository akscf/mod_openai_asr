<p>
  Provides the ability to use OpenAI Speech-To-Text service in the Freeswitch. <br>
  Also capable to work with <a href="https://github.com/akscf/whisperd target="_blank">whisperd</a>
</p>
<p>
If you have problems with building this module, pay attention to this 
  <a href="https://github.com/akscf/mod_openai_asr/issues/1">issue</a> and <a href="https://github.com/akscf/mod_openai_asr/issues/1#issuecomment-2339346528"> the comment</a>, 
  maybe you faced the same thing.
<br><br>
UPD 30-12-2024: <br>
  seems the issue with noises after playback done (play_and_detect_speech) has been fixed in Freeswitch 1.10.10+ (at least in my case)
</p>

### Usage example
```XML
<extension name="openai-asr">
  <condition field="destination_number" expression="^(3222)$">
    <action application="answer"/>
    <action application="play_and_detect_speech" data="/tmp/test2.wav detect:openai"/>
    <action application="sleep" data="1000"/>
    <action application="log" data="CRIT SPEECH_RESULT=${detect_speech_result}"/>
    <action application="hangup"/>
 </condition>
</extension>
```
