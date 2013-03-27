<?php

/**
 * simple-content-introduction.tpl.php
 * Template for Introduction section
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */

// Introduction variables: Enabled?, Header and Body
$introduction_enabled = variable_get('simple_content_introduction_enabled', 0);
$introduction_header = variable_get('simple_content_introduction_header', NULL);
$introduction_body = variable_get('simple_content_introduction_body', NULL);

if ($introduction_enabled == 1):
?>

<div class="introduction-content">

  <?php if (!empty($introduction_header)): ?>
  <div class="introduction-content-header">
    <span class="text"><?php print $introduction_header; ?></span>
  </div>
  <?php endif; ?>

  <?php if (!empty($introduction_body)): ?>
  <div class="introduction-content-body">
    <span class="text"><?php print $introduction_body; ?></span>
  </div>
  <?php endif; ?>

</div>
<!-- Content -->

<?php endif; ?>
