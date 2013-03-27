<?php

/**
 * simple-content-contact.tpl.php
 * Template for Contact section
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */

// Contact variables: Enabled?, Header, Title, Postal, Country, Phone, Fax and Email
$contact_enabled = variable_get('simple_content_contact_enabled', 0);
$contact_header = variable_get('simple_content_contact_header', NULL);
$contact_title = variable_get('simple_content_contact_title', NULL);
$contact_postal = variable_get('simple_content_contact_postal', NULL);
$contact_country = variable_get('simple_content_contact_country', NULL);
$contact_phone = variable_get('simple_content_contact_phone', NULL);
$contact_fax = variable_get('simple_content_contact_fax', NULL);
$contact_email = variable_get('simple_content_contact_email', NULL);

if ($contact_enabled == 1):
?>

<div class="contact-header">
  <?php if (!empty($contact_header)): ?>
  <div class="contact-header-title">
    <span class="text"><?php print $contact_header; ?></span>
  </div>
  <?php endif; ?>
</div>
<!-- Header -->

<div class="contact-entity">

  <?php if (!empty($contact_title)): ?>
  <div class="contact-entity-title">
    <span class="text"><?php print $contact_title; ?></span>
  </div>
  <?php endif; ?>

</div>
<!-- Entity -->

<div class="contact-location">

  <?php if (!empty($contact_postal)): ?>
  <div class="contact-location-postal">
    <span class="text"><?php print $contact_postal; ?></span>
  </div>
  <?php endif; ?>

  <?php if (!empty($contact_country)): ?>
  <div class="contact-location-country">
    <span class="text"><?php print $contact_country; ?></span>
  </div>
  <?php endif; ?>

</div>
<!-- Location -->

<div class="contact-mediums">

  <?php if (!empty($contact_phone)): ?>
  <div class="contact-mediums-phone">
    <span class="label"><?php print t('Phone'); ?></span><br />
    <span class="text"><?php print $contact_phone; ?></span>
  </div>
  <?php endif; ?>

  <?php if (!empty($contact_fax)): ?>
  <div class="contact-mediums-fax">
    <span class="label"><?php print t('Fax'); ?></span><br />
    <span class="text"><?php print $contact_fax; ?></span>
  </div>
  <?php endif; ?>

  <?php if (!empty($contact_email)): ?>
  <div class="contact-mediums-email">
    <span class="label"><?php print t('Email'); ?></span><br />
    <span class="text">
      <a href="mailto:<?php print $contact_email; ?>"><?php print $contact_email; ?></a>
    </span>
  </div>
  <?php endif; ?>

</div>
<!-- Mediums -->

<div class="contact-map">
  <div class="contact-map-image">
    <img src="" />
  </div>
  <div class="contact-map-marker">
    <a href="example.com"><?php print t('Google maps'); ?>
  </div>
</div>
<!-- Map -->

<?php endif; ?>
