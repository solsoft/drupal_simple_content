<?php

/**
 * simple-content-conclusion.tpl.php
 * Template for Conclusion section
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */

// Conclusion variables: Enabled?, Header and Body
$conclusion_enabled = variable_get('simple_content_conclusion_enabled', 0);
$conclusion_header = variable_get('simple_content_conclusion_header', NULL);
$conclusion_body = variable_get('simple_content_conclusion_body', NULL);

if ($conclusion_enabled == 1):
?>

<div class="conclusion-content">

  <?php if (!empty($conclusion_header)): ?>
  <div class="conclusion-content-header">
    <span class="text"><?php print $conclusion_header; ?></span>
  </div>
  <?php endif; ?>

  <?php if (!empty($conclusion_body)): ?>
  <div class="conclusion-content-body">
    <span class="text"><?php print $conclusion_body; ?></span>
  </div>
  <?php endif; ?>

</div>
<!-- Content -->

<?php endif; ?>
