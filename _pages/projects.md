---
layout: archive
title: "Research Projects"
permalink: /projects/
author_profile: true
---

{% for post in site.projects reversed %}
  {% include archive-single-talk.html %}
{% endfor %}
